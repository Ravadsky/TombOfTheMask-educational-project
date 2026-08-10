#pragma once
#include "Core/UObject.h"

class AActor;
class ULevelHUD;
class UPhysicsSubsystem;

class UWorld : public UObject
{
public:
    UWorld() {};

    template <typename actorClass>
    AActor* SpawnActor(const sf::Vector2f& location, const float rotation, const sf::Vector2f& scale)
    {
        static_assert(std::is_base_of_v<AActor, actorClass>, "class must be derived from AActor");

        actorClass* newActor = new actorClass(this);
        newActor->BeginPlay();
        newActor->SetActorLocation(location);
        newActor->SetActorRotation(rotation);
        newActor->SetActorScale(scale);
        return newActor;
    }

    template <typename actorClass>
    AActor* SpawnActorOnCell(const int x_cell, const int y_cell, const float rotation, const sf::Vector2f& scale)
    {
        static_assert(std::is_base_of_v<AActor, actorClass>, "class must be derived from AActor");

        sf::Vector2f worldLocation(x_cell * SPRITE_GAME_SIZE, y_cell * SPRITE_GAME_SIZE);
        SpawnActor<actorClass>(worldLocation, rotation, scale);
    }

    template <typename actorClass>
    std::vector<actorClass*> GetAllActorsOfClass()
    {
        std::vector<actorClass*> actors;
        for (auto actor : ActorsInWorld)
        {
            if (isClassOf<actorClass>(actor))
            {
                actors.push_back(actor);
            }
        }
        return actors;
    }

    template <typename actorClass>
    int GetActorsNumberOfClass()
    {
        int count = 0;
        for (auto actor : ActorsInWorld)
        {
            if (isClassOf<actorClass>(actor))
            {
                count++;
            }
        }
        return count;
    }

    virtual void BeginPlay() override;
    virtual void Update(float deltaTime) override;

    inline UPhysicsSubsystem* GetPhysicsSubsystem() { return physicsSubsystem.get(); };

    void AddActorToWorld(AActor* actor);
    void RemoveActorFromWorld(AActor* actor);

    void AddStar();
    void AddPoint();
    inline int GetStarCount() const { return StarCount; }
    inline int GetPointCount() const { return PointCount; }

    void StartLevel();

private:
    std::vector<AActor*> ActorsInWorld;

    std::string LevelName;
    int PointCountOnLevel, StarCountOnLevel;

    // std::weak_ptr<Actor> CreateObject(sf::Vector2f pos, float rotation, int ID);

    std::unique_ptr<UPhysicsSubsystem> physicsSubsystem;

    int PointCount = 0;
    int StarCount = 0;
    std::unique_ptr<ULevelHUD> LevelHUD;
};
