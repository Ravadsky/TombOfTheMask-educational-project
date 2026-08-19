#pragma once
#include "ActorComponent.h"

class UCameraComponent;

class UCameraShakeComponent : public UActorComponent
{
private:
    UCameraComponent* currentCamera;
    bool bIsActive = false;
    float shakeDuration;
    float shakeTimeElapsed;
    float shakePower = 1.0f;

public:
    UCameraShakeComponent(AActor* componentOwner);

    virtual void Update(float deltaTime) override;

    void StartShake(float duration = 1.0f, float power = 1.0f);
    void EndShake();
};
