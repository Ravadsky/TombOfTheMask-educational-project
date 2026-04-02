#pragma once
#include "UObject.h"
#include <vector>

class Actor;
class Player;

class LevelSubsystem :
    public UObject
{
private:

public:
    std::vector<std::shared_ptr<Actor>> ActorsOnLevel;

    std::weak_ptr<Player> CurrentPlayer;

    LevelSubsystem();
    void BeginPlay() override;
    void Update() override;

    void StartLevel();
    void RestartLevel();

    void CreateBackground();
    void CreateStaticObjects();
    void CreateDynamicObjects();
};

