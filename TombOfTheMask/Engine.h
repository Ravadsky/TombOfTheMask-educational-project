#pragma once
#include "GameState.h"
#include "RenderSubsystem.h"
#include "UObject.h"
#include <functional>

class Engine : public UObject
{
  private:
    std::unique_ptr<GameState> CurrentGameState;
    bool needToSwitchState = false;

    // Запомнить в какое окно переключить игру в начале кадра
    std::function<std::unique_ptr<GameState>()> PendingState;

  public:
    Engine();

    void Update() override;

    template <typename T> inline void SwitchState()
    {
        needToSwitchState = true;
        PendingState = []() -> std::unique_ptr<GameState> { return std::make_unique<T>(); };
    }
};
