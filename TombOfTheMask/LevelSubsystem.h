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
    std::vector<Actor*> ActorsOnLevel;

    Player* CurrentPlayer;

    LevelSubsystem();
    void BeginPlay() override;
    void Update() override;
};

