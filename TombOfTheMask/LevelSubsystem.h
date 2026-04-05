#pragma once
#include "UObject.h"
#include "functional"
#include <unordered_map>
#include <vector>

class Actor;
class Player;

class LevelSubsystem : public UObject
{
  private:
    std::unordered_map<int, std::function<std::weak_ptr<Actor>(sf::Vector2f, float)>> ActorsID;

  public:
    bool needToStartLevel = true;

    int PointCountOnLevel, StarCountOnLevel;

    std::vector<std::shared_ptr<Actor>> ActorsOnLevel;

    std::weak_ptr<Player> CurrentPlayer;

    LevelSubsystem();
    void BeginPlay() override;
    void Update() override;

    void CheckStartingLevel();

    std::weak_ptr<Actor> CreateObject(sf::Vector2f pos, float rotation, int ID);

    template <typename T> inline void AddBindActorID(int ID)
    {
        ActorsID[ID] = [](sf::Vector2f pos, float rotation) { return SpawnActor<T>(pos, rotation); };
    }
};
