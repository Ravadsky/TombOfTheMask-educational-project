#include "CameraShakeComponent.h"

UCameraShakeComponent::UCameraShakeComponent(AActor* componentOwner) : UActorComponent(componentOwner) {}

void UCameraShakeComponent::Update(float deltaTime)
{
    UActorComponent::Update(deltaTime);

    if (bIsActive)
    {
        shakeTimeElapsed += deltaTime;

        if (shakeTimeElapsed >= shakeDuration)
            EndShake();

        else
        {
            auto& shakeView = Window->getDefaultView();

            float intensity = 1.f - (shakeTimeElapsed / shakeDuration);

        }
    }
}

void UCameraShakeComponent::StartShake(float duration, float power)
{
    bIsActive = true;
    shakeDuration = duration;
    shakePower = power;
    shakeTimeElapsed = 0.0f;
}

void UCameraShakeComponent::EndShake()
{
    bIsActive = false;
    shakeDuration = 0.0f;
    shakePower = 0.0f;
    shakeTimeElapsed = 0.0f;
}
