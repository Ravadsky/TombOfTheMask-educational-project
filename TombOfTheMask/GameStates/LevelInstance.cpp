#include "LevelInstance.h"
#include "World/World.h"

ULevelInstance::ULevelInstance()
{
    WorldInstance = std::make_unique<UWorld>();
    WorldInstance->StartLevel();
}

void ULevelInstance::Update(float deltaTime)
{
    WorldInstance->Update(deltaTime);
}
