#pragma once
#include "Actor.h"

class UAnimatedSpriteComponent;

class AEffect : public AActor
{
public:
    AEffect(UWorld* InWorld);
    virtual ~AEffect() = default;

    void TriggerEffect(std::string effectName, bool isLooping = false, int framesCount = 6);
    void DestroyEffect();

    virtual void Update(float deltaTime) override;
    virtual void BeginPlay() override;

private:
    UAnimatedSpriteComponent* animatedSpriteComponent;
    bool bIsLoopingEffect = false;
};
