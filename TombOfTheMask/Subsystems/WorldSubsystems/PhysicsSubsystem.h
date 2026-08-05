#pragma once
#include "Core/UObject.h"

#include "Core/FunctionLibrary/UtilityFunctions.h"

class Actor;

class PhysicsSubsystem : public UObject
{
  private:
    sf::Clock GameClock;
    sf::Time DeltaTimer;
    float DeltaTime = 0.f;

  public:
    std::vector<std::weak_ptr<Actor>> TriggerActors;

    PhysicsSubsystem();
    virtual void Update() override;

    float GetElapsedTime();
};
