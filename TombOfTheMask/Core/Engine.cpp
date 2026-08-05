#include "Engine.h"
#include "GameStates/GameState.h"

#include "Subsystems/GameSubsystems/AudioSubsystem.h"
#include "Subsystems/GameSubsystems/GarbageCollector.h"
#include "Subsystems/GameSubsystems/RenderSubsystem.h"
#include "Subsystems/GameSubsystems/ResourceSubsystem.h"

GEngine::GEngine()
{
    // init game instance subsystems
    GResourceSubsystem = new ResourceSubsystem();
    GAudioSubsystem = new AudioSubsystem();
    GGarbageCollector = new GarbageCollector();
    GRenderSubsystem = new RenderSubsystem();

    /// start game state from main menu
    SwitchState<MainMenu>();
}

GEngine::~GEngine()
{
    delete GResourceSubsystem;
    delete GAudioSubsystem;
    delete GGarbageCollector;
    delete GGarbageCollector;
}

void GEngine::Update()
{
    if (needToSwitchState)
        SwitchGameState();

    if (CurrentGameState)
        CurrentGameState->Update();

    // update visual and audio after logic
    GRenderSubsystem->Update();
    GAudioSubsystem->Update();

    // collect garbage after all
    GGarbageCollector->Update();
}

void GEngine::SwitchGameState()
{
    sf::sleep(sf::milliseconds(TimeBeetweenStates));
    CurrentGameState = PendingState();
    CurrentGameState->BeginPlay();

    PendingState = nullptr;
    needToSwitchState = false;
}