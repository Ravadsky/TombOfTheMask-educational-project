#include "LevelInstance.h"

#include "AudioSubsystem.h"
#include "InputSubsystem.h"
#include "LevelSubsystem.h"
#include "PhysicsSubsystem.h"

LevelInstance::LevelInstance()
{
    LevelSS = std::make_unique<LevelSubsystem>();
    GLevelSubsystem = LevelSS.get();

    PhysicsSS = std::make_unique<PhysicsSubsystem>();
    GPhysicsSubsystem = PhysicsSS.get();

    InputSS = std::make_unique<InputSubsystem>();
    GInputSubsystem = InputSS.get();

    GAudioSubsystem->StartNewMusic("level_music");

    GLevelSubsystem->StartLevel();
}

void LevelInstance::Update()
{
    GInputSubsystem->Update();

    GLevelSubsystem->Update();

    GPhysicsSubsystem->Update();
}
