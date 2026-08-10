#include "World.h"
#include "PhysicsSubsystem.h"
#include "Core/GameSubsystems/AudioSubsystem.h"
#include "Actors/Actor.h"
#include "GUI/LevelHUD.h"
#include "Core/DataFunctions.h"

void UWorld::BeginPlay()
{
    LevelHUD = std::make_unique<ULevelHUD>();

    // PointCountWidget = std::make_unique<Widget>(sf::Vector2f(64, 64), "Point", PointText);
    // StarCountWidget = std::make_unique<Widget>(sf::Vector2f(64, 128), "Star", StarText);
}

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
    physicsSubsystem = std::make_unique<UPhysicsSubsystem>();
    GetAudioSubsystem()->StartNewMusic("level_music");

         PointCountOnLevel = 0;
         StarCountOnLevel = 0;
    
             LevelName = "Level" + std::to_string(GetDataParameter("CurrentLevel:"));
         std::ifstream file(RESOURCES_PATH + "Levels/" + LevelName + ".txt");
    
    //     std::string line;
    //     while (std::getline(file, line))
    //     {
    //         std::istringstream stream(line);
    //         int xPos, yPos, Rotation, ActorID;
    //         char commaSeparator;
    //
    //         stream >> ActorID >> commaSeparator >> xPos >> commaSeparator >> yPos >> commaSeparator >> Rotation;
    //
    //         CreateObject({ (float)xPos, (float)yPos }, (float)Rotation, ActorID);
    //
    //         if (ActorID == 6 or ActorID == 7)
    //         {
    //             CreateObject({ (float)xPos, (float)yPos }, 0, 12);
    //         }
    //     }
    //
    //     PointCountOnLevel = GetCountOfActorsOf<Point>();
    //     StarCountOnLevel = GetCountOfActorsOf<Star>();
    //
    //     for (auto _actor : ActorsOnLevel)
    //     {
    //         _actor->BeginPlay();
    //     }
}

void UWorld::AddPoint()
{
    ++PointCount;
    LevelHUD->UpdateHUDState(StarCount, PointCount);
}

void UWorld::AddStar()
{
    ++StarCount;
    LevelHUD->UpdateHUDState(StarCount, PointCount);
}