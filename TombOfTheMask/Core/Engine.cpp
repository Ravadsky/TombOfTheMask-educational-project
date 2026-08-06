#include "CoreMinimal.h"

#include "GameStates/GameState.h"
#include "GameStates/MainMenu.h"

#include "Core/GameSubsystems/AudioSubsystem.h"
#include "Core/GameSubsystems/GarbageCollector.h"
#include "Core/GameSubsystems/RenderSubsystem.h"
#include "Core/GameSubsystems/ResourceSubsystem.h"

sf::RenderWindow* GWindow;
GEngine* Engine;

GEngine::GEngine()
{
    // init game instance subsystems
    resourceSubsystem = std::make_unique<UResourceSubsystem>();
    renderSubsystem = std::make_unique<URenderSubsystem>();
    audioSubsystem = std::make_unique<UAudioSubsystem>();
    garbageCollector = std::make_unique<UGarbageCollector>();

    /// start game state from main menu
    MarkToSwitchState<MainMenu>();
}

GEngine::~GEngine() {}

void GEngine::Update()
{
    if (needToSwitchState)
        SwitchGameState();

    resourceSubsystem->Update();

    if (CurrentGameState)
        CurrentGameState->Update();

    // update visual and audio after logic
    renderSubsystem->Update();
    audioSubsystem->Update();

    // collect garbage after all
    garbageCollector->Update();
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

void GEngine::SwitchGameState()
{
    sf::sleep(TimeBeetweenStates);
    CurrentGameState = PendingState();
    CurrentGameState->BeginPlay();

    PendingState = nullptr;
    needToSwitchState = false;
}