#include "Engine.h"
#include "GameState.h"
#include "GarbageCollector.h"
#include "InputSubsystem.h"
#include "LevelInstance.h"
#include "LevelSubsystem.h"
#include "PhysicsSubsystem.h"
#include "RenderSubsystem.h"
#include "ResourceSubsystem.h"
#include "MainMenu.h"

Engine::Engine()
{
    // инициализировать глобальные ресурсы
    GResourceSubsystem = new ResourceSubsystem();
    // GRenderSubsystem = new RenderSubsystem();
    GGarbageCollector = new GarbageCollector();

    SwitchState<MainMenu>();
}

void Engine::Update()
{
    if (needToSwitchState)
    {
        CurrentGameState = PendingState();
        PendingState = nullptr;

        CurrentGameState->BeginPlay();

        needToSwitchState = false;
    }

    if (CurrentGameState)
    {
        // Обновление текущего игрового окна
        CurrentGameState->Update();
    }
    // Отрисовка объектов (в том числе интерфейсов) на экран
    GRenderSubsystem->Update();
    // удаление объектов в конце кадра
    GGarbageCollector->Update();
}
