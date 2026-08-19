#include "CameraShakeComponent.h"

UCameraShakeComponent::UCameraShakeComponent(AActor* componentOwner) : UActorComponent(componentOwner) {}

void UCameraShakeComponent::Update(float deltaTime)
{
    UActorComponent::Update(deltaTime);

    if (bIsActive)
    {
        shakeTimeElapsed += deltaTime;

        if (shakeTimeElapsed >= shakeDuration)
        {
            EndShake();
            return;
        }

        float intensity = 1.f - (shakeTimeElapsed / shakeDuration);
        float offsetX = (rand() / (float)RAND_MAX - 0.5f) * intensity * shakePower;
        float offsetY = (rand() / (float)RAND_MAX - 0.5f) * intensity * shakePower;
        sf::Vector2f Offset(offsetX, offsetY);

        sf::View shakeView = Window->getDefaultView();
        shakeView.setCenter(Offset + CAMERA_PIVOT);
        Window->setView(shakeView);
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

    sf::View shakeView = Window->getDefaultView();
    shakeView.setCenter(CAMERA_PIVOT);
    Window->setView(shakeView);
}
