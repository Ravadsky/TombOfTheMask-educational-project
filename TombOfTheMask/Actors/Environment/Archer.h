#pragma once
#include "Actors/Actor.h"
#include "Components/MovementComponent.h"

class AArcher : public AActor
{
private:
    float timer = 0.f;
    sf::Vector2f CellPosition;

public:
    AArcher(UWorld* InWorld);

    virtual void Update(float deltaTime) override;
};

// archer projectile
class AArrow : public AActor
{
public:
    AArrow(UWorld* InWorld);

    virtual void Update(float deltaTime) override;
    virtual void BeginPlay() override;

    void SetInitialDirection(EMovementDirection direction);

private:
    void DamageTarget(UColliderComponent* otherCollider);

    UMovementComponent* MovementComponent;

    EMovementDirection InitialDirection = EMovementDirection::Down;
};
