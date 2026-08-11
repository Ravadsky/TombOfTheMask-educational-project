#include "World.h"
#include "PhysicsSubsystem.h"
#include "Core/GameSubsystems/AudioSubsystem.h"
#include "Actors/Actor.h"
#include "Core/DataFunctions.h"
#include "Actors/ManagerActorID.h"
#include <sstream>

#include "Actors/Point.h"
#include "Actors/Star.h"

UWorld::UWorld()
{
    actorsID = std::make_unique<ManagerActorID>(this);

    physicsSubsystem = std::make_unique<UPhysicsSubsystem>();
    GetAudioSubsystem()->StartNewMusic("level_music");
}

AActor* UWorld::SpawnActorOnCellByID(const int ID, const int x_cell, const int y_cell, const float rotation,
                                     const sf::Vector2f& scale)
{
    sf::Vector2f worldLocation((float)x_cell * SPRITE_GAME_SIZE, (float)y_cell * SPRITE_GAME_SIZE);
    auto newActor = actorsID->Create(ID);
    newActor->BeginPlay();
    newActor->SetActorLocation(worldLocation);
    newActor->SetActorRotation(rotation);
    newActor->SetActorScale(scale);
    return newActor;
}

void UWorld::BeginPlay() {}

void UWorld::Update(float deltaTime)
{
    for (auto actor : ActorsInWorld)
    {
        actor->Update(deltaTime);
    }
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
    }
    PointCountOnLevel = GetActorsNumberOfClass<APoint>();
    StarCountOnLevel = GetActorsNumberOfClass<AStar>();
}