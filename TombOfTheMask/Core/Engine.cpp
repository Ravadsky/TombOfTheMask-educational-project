#include "CoreMinimal.h"

#include "GameStates/GameState.h"

#include "Core/GameSubsystems/AudioSubsystem.h"
#include "Core/GameSubsystems/GarbageCollector.h"
#include "Core/GameSubsystems/RenderSubsystem.h"
#include "Core/GameSubsystems/ResourceSubsystem.h"

sf::RenderWindow* Window = nullptr;
GEngine* Engine;

GEngine::GEngine() {}

GEngine::~GEngine() {}

void GEngine::Update()
{
    deltaTime = GameClock.restart().asSeconds();
    if (needToSwitchState)
        SwitchGameState();

    resourceSubsystem->Update(deltaTime);

    if (CurrentGameState)
        CurrentGameState->Update(deltaTime);

    // update visual and audio after logic
    renderSubsystem->Update(deltaTime);
    audioSubsystem->Update(deltaTime);

    // collect garbage after all
    garbageCollector->Update(deltaTime);
}

void GEngine::RegisterObject(UObject* object)
{
    AllObjects.push_back(object);
}

void GEngine::UnregisterObject(UObject* object)
{
    auto objectIterator = std::find(AllObjects.begin(), AllObjects.end(), object);
    if (objectIterator != AllObjects.end())
        AllObjects.erase(objectIterator);
}

void GEngine::RegisterSubsystems()
{
    // init game instance subsystems
    resourceSubsystem = std::make_unique<UResourceSubsystem>();
    renderSubsystem = std::make_unique<URenderSubsystem>();
    audioSubsystem = std::make_unique<UAudioSubsystem>();
    garbageCollector = std::make_unique<UGarbageCollector>();
}

void GEngine::SwitchGameState()
{
    sf::sleep(TimeBeetweenStates);
    CurrentGameState = PendingState();
    CurrentGameState->BeginPlay();

    PendingState = nullptr;
    needToSwitchState = false;
}