#pragma once
#include "UObject.h"
#include <functional>

class GameState;

class GEngine : public UObject
{
public:
    GEngine();
    ~GEngine();

    virtual void Update() override;

    template <typename T>
    inline void MarkToSwitchState()
    {
        needToSwitchState = true;
        PendingState = []() -> std::unique_ptr<GameState> { return std::make_unique<T>(); };
    }

private:
    void SwitchGameState();

    bool needToSwitchState = false;
    std::unique_ptr<GameState> CurrentGameState;
    std::function<std::unique_ptr<GameState>()> PendingState;
};
