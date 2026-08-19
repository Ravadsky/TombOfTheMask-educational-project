#include "LevelInstance.h"
#include "World/World.h"

ULevelInstance::ULevelInstance() : UGameState()
{
    WorldInstance = std::make_unique<UWorld>();
    WorldInstance->StartLevel();

    onEscapePressed.Add(this, &ULevelInstance::EndLevelInstance);
}

void ULevelInstance::EndLevelInstance()
{
    WorldInstance->DestoyLevel();
}

void ULevelInstance::Update(float deltaTime)
{
    WorldInstance->Update(deltaTime);

    UGameState::Update(deltaTime);
}
