#pragma once
#include "Core/UObject.h"

class UGameState : public UObject
{
public:
    virtual ~UGameState() = default;
    virtual void BeginPlay() override {};
    virtual void Update(float deltaTime) override {};
};
