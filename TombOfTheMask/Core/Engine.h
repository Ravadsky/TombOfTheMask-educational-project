#pragma once
#include <functional>
#include <vector>

class UGameState;

class UObject;
class URenderSubsystem;
class UResourceSubsystem;
class UAudioSubsystem;
class UGarbageCollector;

class GEngine
{
public:
    GEngine();
    ~GEngine();

    void Update();

    template <typename T>
    inline void MarkToSwitchState()
    {
        needToSwitchState = true;
        PendingState = []() -> std::unique_ptr<UGameState> { return std::make_unique<T>(); };
    }

    inline URenderSubsystem* GetRenderSubsystem() const { return renderSubsystem.get(); };
    inline UResourceSubsystem* GetResourceSubsystem() const { return resourceSubsystem.get(); };
    inline UAudioSubsystem* GetAudioSubsystem() const { return audioSubsystem.get(); };
    inline UGarbageCollector* GetGarbageCollector() const { return garbageCollector.get(); };

    void RegisterObject(UObject* object);
    void UnregisterObject(UObject* object);

    void RegisterSubsystems();

    inline void SetSleepingTime(int inMilliseconds) { sleepingTimeBetweenFrames = inMilliseconds; }

private:
    void SwitchGameState();

    bool needToSwitchState = false;
    std::unique_ptr<UGameState> CurrentGameState;
    std::function<std::unique_ptr<UGameState>()> PendingState;

    std::unique_ptr<URenderSubsystem> renderSubsystem;
    std::unique_ptr<UResourceSubsystem> resourceSubsystem;
    std::unique_ptr<UAudioSubsystem> audioSubsystem;
    std::unique_ptr<UGarbageCollector> garbageCollector;

    std::vector<UObject*> AllObjects;

    sf::Clock GameClock;
    float deltaTime = 0.f;

    int sleepingTimeBetweenFrames = 0;
    void SleepToNextFrame();
};
