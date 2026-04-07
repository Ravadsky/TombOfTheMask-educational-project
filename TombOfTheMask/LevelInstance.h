#pragma once
#include "GameState.h"
#include "LevelSubsystem.h"
#include "InputSubsystem.h"
#include "PhysicsSubsystem.h"
#include "RenderSubsystem.h"

class LevelInstance : public GameState
{
  private:
    std::unique_ptr<LevelSubsystem> LevelSS;
    std::unique_ptr<PhysicsSubsystem> PhysicsSS;
    std::unique_ptr<InputSubsystem> InputSS;
    std::unique_ptr<RenderSubsystem> RenderSS;

  public:
    LevelInstance();

    void Update() override;
};
