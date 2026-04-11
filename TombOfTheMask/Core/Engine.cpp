#include "Engine.h"

#include "AudioSubsystem.h"
#include "GarbageCollector.h"
#include "RenderSubsystem.h"
#include "ResourceSubsystem.h"

#include "MainMenu.h"

Engine::Engine()
{
    // инициализировать глобальные ресурсы
    GResourceSubsystem = new ResourceSubsystem();
    // инициализировать глобальные ресурсы
    GAudioSubsystem = new AudioSubsystem();
    // GRenderSubsystem = new RenderSubsystem();
    GGarbageCollector = new GarbageCollector();

    GRenderSubsystem = new RenderSubsystem();

    SwitchState<MainMenu>();
}

void Engine::Update()
{
    // Обновление игрового окна в начале кадра
    if (needToSwitchState)
    {
        sf::sleep(sf::milliseconds(TimeBeetweenStates));
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
    // Обработка аудио-сэмплов
    GAudioSubsystem->Update();
    // удаление объектов в конце кадра
    GGarbageCollector->Update();
}
