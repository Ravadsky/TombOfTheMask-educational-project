#pragma once
#include "UObject.h"

#include "VectorFunctions.h"

class Actor;
class Player;

class LevelSubsystem : public UObject
{
  public:
    std::string LevelName;
    int PointCountOnLevel, StarCountOnLevel;

    std::vector<std::shared_ptr<Actor>> ActorsOnLevel;
    std::weak_ptr<Player> CurrentPlayer;

    LevelSubsystem();
    virtual void Update() override;

    std::weak_ptr<Actor> CreateObject(sf::Vector2f pos, float rotation, int ID);

    void StartLevel();
};
