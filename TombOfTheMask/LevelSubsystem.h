#pragma once
#include "UObject.h"
#include <vector>
#include "Actor.h"

class LevelSubsystem :
    public UObject
{
private:

public:
    std::vector<Actor*> ActorsOnLevel;

    LevelSubsystem();
    void BeginPlay() override;
    void Update() override;
};

