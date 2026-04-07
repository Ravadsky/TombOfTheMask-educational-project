#include "LevelInstance.h"
#include "InputSubsystem.h"
#include "PhysicsSubsystem.h"
#include "RenderSubsystem.h"

LevelInstance::LevelInstance()
{
    LevelSS = std::make_unique<LevelSubsystem>();
    GLevelSubsystem = LevelSS.get();

    PhysicsSS = std::make_unique<PhysicsSubsystem>();
    GPhysicsSubsystem = PhysicsSS.get();

    InputSS = std::make_unique<InputSubsystem>();
    GInputSubsystem = InputSS.get();

    RenderSS = std::make_unique<RenderSubsystem>();
    GRenderSubsystem = RenderSS.get();
}

void LevelInstance::Update()
{
    GInputSubsystem->Update();

    GLevelSubsystem->Update();

    GPhysicsSubsystem->Update();
}
