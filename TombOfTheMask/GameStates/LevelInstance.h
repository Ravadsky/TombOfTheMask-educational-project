#pragma once
#include "GameState.h"

class LevelSubsystem;
class PhysicsSubsystem;
class InputSubsystem;

class LevelInstance : public GameState
{
  private:
    std::unique_ptr<LevelSubsystem> LevelSS;
    std::unique_ptr<PhysicsSubsystem> PhysicsSS;
    std::unique_ptr<InputSubsystem> InputSS;

  public:
    LevelInstance();

    virtual void Update() override;
};
