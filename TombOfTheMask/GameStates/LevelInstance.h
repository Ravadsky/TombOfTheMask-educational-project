#pragma once
#include "GameState.h"

class LevelInstance : public GameState
{
public:
    LevelInstance();

    virtual void Update(float deltaTime) override;
};
