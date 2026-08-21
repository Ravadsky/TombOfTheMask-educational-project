#include "World.h"
#include "PhysicsSubsystem.h"
#include "Core/GameSubsystems/AudioSubsystem.h"
#include "Actors/Actor.h"
#include "Core/DataFunctions.h"
#include <sstream>

#include "Actors/Effect.h"
#include "Actors/Environment/Point.h"
#include "Actors/Environment/Star.h"
#include "Core/GameSubsystems/ResourceSubsystem.h"

UWorld::UWorld()
{
    physicsSubsystem = new UPhysicsSubsystem;
    GetAudioSubsystem()->StartNewMusic("level_music");
}

UWorld::~UWorld() {}

AActor* UWorld::SpawnActorOnCellByID(const int ID, const int x_cell, const int y_cell, const float rotation,
                                     const sf::Vector2f& scale)
{
    sf::Vector2f worldLocation((float)x_cell * SPRITE_GAME_SIZE, (float)y_cell * SPRITE_GAME_SIZE);
    auto newActor = GetResourceSubsystem()->Create(ID, this);
    newActor->SetActorLocation(worldLocation);
    newActor->SetActorRotation(rotation);
    newActor->SetActorScale(scale);
    newActor->BeginPlay();
    return newActor;
}

void UWorld::BeginPlay() {}

void UWorld::Update(float deltaTime)
{
    ProcessDelayedActions();

    for (auto actor : ActorsInWorld)
    {
        if (actor->CanTick())
            actor->Update(deltaTime);
    }

    physicsSubsystem->Update(deltaTime);
}

void UWorld::AddActorToWorld(AActor* actor)
{
    ActorsInWorld.push_back(actor);
}

void UWorld::RemoveActorFromWorld(AActor* actor)
{
    auto objectIterator = std::find(ActorsInWorld.begin(), ActorsInWorld.end(), actor);
    if (objectIterator != ActorsInWorld.end())
        ActorsInWorld.erase(objectIterator);
}

void UWorld::StartLevel()
{
    bIsEditorMode = false;

    PointCountOnLevel = 0;
    StarCountOnLevel = 0;

    LevelName = "Level" + std::to_string(GetDataParameter("CurrentLevel:"));
    std::ifstream file(RESOURCES_PATH + "Levels/" + LevelName + ".txt");

    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream stream(line);
        int xPos, yPos, Rotation, ActorID;
        char commaSeparator;

        stream >> ActorID >> commaSeparator >> xPos >> commaSeparator >> yPos >> commaSeparator >> Rotation;

        SpawnActorOnCellByID(ActorID, xPos, yPos, (float)Rotation);

        // установка стен за объекты
        SpawnActorOnCellByID(2, xPos, yPos, 0.0f);
    }
    PointCountOnLevel = GetActorsNumberOfClass<APoint>();
    StarCountOnLevel = GetActorsNumberOfClass<AStar>();
}

void UWorld::DestoyLevel()
{
    for (auto actor : ActorsInWorld)
        actor->MarkAsGarbage();

    physicsSubsystem->MarkAsGarbage();
}

void UWorld::AddDelayedAction(std::function<void()> Action)
{
    DelayedActions.push_back(Action);
}

void UWorld::ProcessDelayedActions()
{
    for (auto& action : DelayedActions)
        action();

    DelayedActions.clear();
}

void UWorld::SpawnEffect(std::string effectName, bool isLooping, int framesCount, const sf::Vector2f& location,
                         const float rotation, const sf::Vector2f& scale)
{
    AddDelayedAction(
        [this, effectName, isLooping, framesCount, location, rotation, scale]()
        {
            auto effect = SpawnActor<AEffect>(location, rotation, scale);
            effect->TriggerEffect(effectName, isLooping, framesCount);
        });
}
