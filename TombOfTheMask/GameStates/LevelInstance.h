#pragma once
#include "GameState.h"

class UWorld;

class ULevelInstance : public UGameState
{
public:
    ULevelInstance();

    virtual void Update(float deltaTime) override;

private:
    std::unique_ptr<UWorld> WorldInstance;

    void EndLevelInstance();
};
