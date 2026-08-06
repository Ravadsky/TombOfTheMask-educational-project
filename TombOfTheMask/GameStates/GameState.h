#pragma once
#include "Core/UObject.h"

class GameState : public UObject
{
public:
    virtual ~GameState() = default;
    virtual void BeginPlay() override {};
    virtual void Update(float deltaTime) override {};
};
