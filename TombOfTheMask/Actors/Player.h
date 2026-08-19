#pragma once
#include "Actor.h"

class UInputComponent;
class UMovementComponent;
class UCameraComponent;
class UViewportComponent;
class UCameraShakeComponent;

class APlayer : public AActor
{
public:
    APlayer(UWorld* InWorld);

    void GetDamage();

private:
    UInputComponent* InputComponent;
    UMovementComponent* MovementComponent;
    UCameraComponent* CameraComponent;
    UViewportComponent* ViewportComponent;
    UCameraShakeComponent* CameraShakeComponent;

    void StopMovement(UColliderComponent* otherCollider);
};
