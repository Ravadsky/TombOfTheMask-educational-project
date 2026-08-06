#pragma once
#include "UObject.h"
#include "Actors/Actor.h"

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

private:
    std::vector<AActor*> ActorsInWorld;
};
