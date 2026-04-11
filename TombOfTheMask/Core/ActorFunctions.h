#pragma once
#include "CoreMinimal.h"

#include "LevelSubsystem.h"

// Взаимодействие с системой Акторов
template <typename T> inline std::weak_ptr<T> SpawnActor(sf::Vector2f cellPosition, float rotationAngle = 0.f)
{
    sf::Vector2f WorldPosition = {cellPosition.x * SPRITE_GAME_SIZE, cellPosition.y * SPRITE_GAME_SIZE};
    auto TempActor = std::make_shared<T>(WorldPosition, rotationAngle);
    GLevelSubsystem->ActorsOnLevel.emplace_back(TempActor);
    return TempActor;
}
template <typename T, typename K> inline bool isClassOf(const std::shared_ptr<K> &object)
{
    return object && std::dynamic_pointer_cast<T>(object) != nullptr;
}
template <typename T, typename K> inline std::shared_ptr<T> CastTo(const std::shared_ptr<K> &object)
{
    return std::dynamic_pointer_cast<T>(object);
}
template <typename T> inline int GetCountOfActorsOf()
{
    int actorCount = 0;
    for (auto actor : GLevelSubsystem->ActorsOnLevel)
    {
        if (isClassOf<T>(actor))
            actorCount++;
    }
    return actorCount;
}