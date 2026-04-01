#pragma once
#include "UObject.h"

class Actor;

class PhysicsSubsystem :
    public UObject
{
public:
    PhysicsSubsystem();
    void BeginPlay() override;
    void Update() override;
};

