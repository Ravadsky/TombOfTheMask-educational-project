#pragma once
#include "UObject.h"

#include <functional>

class GameState;

class Engine : public UObject
{
  private:
    std::unique_ptr<GameState> CurrentGameState;
    bool needToSwitchState = false;

    // Запомнить в какое окно переключить игру в начале кадра
    std::function<std::unique_ptr<GameState>()> PendingState;

  public:
    Engine();

    virtual void Update() override;

    template <typename T> inline void SwitchState()
    {
        needToSwitchState = true;
        PendingState = []() -> std::unique_ptr<GameState> { return std::make_unique<T>(); };
    }
};
