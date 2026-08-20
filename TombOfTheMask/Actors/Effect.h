#pragma once
#include "Actor.h"

class UAnimatedSpriteComponent;

class AEffect : public AActor
{
public:
    AEffect(UWorld* InWorld);

    void TriggerEffect(std::string effectName, bool isLooping = false);
    void DestroyEffect();

private:
    UAnimatedSpriteComponent* animatedSpriteComponent;
    bool bIsLoopingEffect = false;

};
