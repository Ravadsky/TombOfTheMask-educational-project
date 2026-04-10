#pragma once
#include "Actor.h"
#include "CoreMinimal.h"
#include "GarbageCollector.h"
#include "LevelSubsystem.h"
#include "PhysicsSubsystem.h"
#include "assert.h"
#include <algorithm>
#include <fstream>
#include <memory>
#include <numbers>
#include <typeinfo>

template <typename T> inline std::weak_ptr<T> SpawnActor(sf::Vector2f cellPosition, float rotationAngle = 0.f)
{
    sf::Vector2f WorldPosition = {cellPosition.x * SPRITE_GAME_SIZE, cellPosition.y * SPRITE_GAME_SIZE};
    auto TempActor = std::make_shared<T>(WorldPosition, rotationAngle);
    GLevelSubsystem->ActorsOnLevel.emplace_back(TempActor);
    return TempActor;
}

inline sf::Vector2f RotateVector(sf::Vector2f baseVector, float rotationAngle)
{
    const float rotationInRadians = rotationAngle * (float)std::numbers::pi / 180.f;
    float sinAngle = std::sin(rotationInRadians);
    float cosAngle = std::cos(rotationInRadians);

    return sf::Vector2f(baseVector.x * cosAngle - baseVector.y * sinAngle,
                        baseVector.x * sinAngle + baseVector.y * cosAngle);
}

template <typename T> inline void ClearVectorForExpiredPtr(std::vector<std::weak_ptr<T>> vec)
{
    auto iter =
        std::remove_if(vec.begin(), vec.end(), [](const std::weak_ptr<T> &pointer) { return pointer.expired(); });
    vec.erase(iter, vec.end());
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

template <typename T> inline bool Timer(float time)
{
    static float intern_time = 0.f;
    intern_time += GPhysicsSubsystem->GetElapsedTime();
    if (intern_time >= time)
    {
        intern_time -= time;
        return true;
    }
    return false;
}

template <typename T> inline T Clamp(T &Object, T min, T max)
{
    if (min > Object)
        return min;
    if (Object > max)
        return max;
    return Object;
}

inline void ChangeDataParamater(std::string key, int NewParamater)
{
    std::ifstream fileIn(RESOURCES_PATH + "PlayerData.txt");
    assert(fileIn.is_open());

    std::vector<std::string> lines;
    std::string line;
    bool keyIsFounded = false;
    while (std::getline(fileIn, line))
    {
        if (line.find(key) == 0)
        {
            line = key + std::to_string(NewParamater);
            keyIsFounded = true;
        }
        lines.push_back(line);
    }
    fileIn.close();

    if (!keyIsFounded)
        lines.push_back(key + std::to_string(NewParamater));

    std::ofstream fileOut(RESOURCES_PATH + "PlayerData.txt");
    for (auto &line : lines)
        fileOut << line << '\n';
}

inline int GetDataParameter(std::string key)
{
    std::ifstream fileIn(RESOURCES_PATH + "PlayerData.txt");

    std::string line;
    while (std::getline(fileIn, line))
    {
        if (line.find(key) == 0)
            return std::stoi(line.substr(key.length()));
    }
    // обработка, если key - ошибка
    return -1;
}