#pragma once
#include "Actors/Actor.h"
#include "Components/MovementComponent.h"

class AArrow : public AActor
{
public:
    AArrow(UWorld* InWorld);

    virtual void Update(float deltaTime) override;
    virtual void BeginPlay() override;

    EMovementDirection InitialDirection = EMovementDirection::Down;

private:
    void DamageTarget(UColliderComponent* otherCollider);

    UMovementComponent* MovementComponent;
};
