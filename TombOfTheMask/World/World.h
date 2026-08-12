#pragma once
#include "Core/UObject.h"

class AActor;
class UPhysicsSubsystem;

class UWorld : public UObject
{
public:
    UWorld();
    ~UWorld();

    template <typename actorClass>
    actorClass* SpawnActor(const sf::Vector2f& location, const float rotation, const sf::Vector2f& scale = { 1, 1 })
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
    actorClass* SpawnActorOnCell(const int x_cell, const int y_cell, const float rotation,
                                 const sf::Vector2f& scale = { 1, 1 })
    {
        static_assert(std::is_base_of_v<AActor, actorClass>, "class must be derived from AActor");

        sf::Vector2f worldLocation((float)x_cell * SPRITE_GAME_SIZE, (float)y_cell * SPRITE_GAME_SIZE);
        return SpawnActor<actorClass>(worldLocation, rotation, scale);
    }

    AActor* SpawnActorOnCellByID(const int ID, const int x_cell, const int y_cell, const float rotation,
                                 const sf::Vector2f& scale = { 1, 1 });

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

    inline UPhysicsSubsystem* GetPhysicsSubsystem() { return physicsSubsystem; };

    void AddActorToWorld(AActor* actor);
    void RemoveActorFromWorld(AActor* actor);

    void StartLevel();
    void DestoyLevel();

    bool bIsEditorMode = true;

private:
    std::vector<AActor*> ActorsInWorld;

    std::string LevelName;
    int PointCountOnLevel, StarCountOnLevel;

    UPhysicsSubsystem* physicsSubsystem;
};
