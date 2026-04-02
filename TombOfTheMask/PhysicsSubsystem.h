#pragma once
#include "UObject.h"
#include <vector>

class Actor;

class PhysicsSubsystem :
    public UObject
{
private:
    sf::Clock GameClock;
    sf::Time DeltaTimer;
    float DeltaTime = 0.f;

public:
    std::vector<std::weak_ptr<Actor>> TriggerActors;

    PhysicsSubsystem();
    void BeginPlay() override;
    void Update() override;

    float GetElapsedTime();
};

