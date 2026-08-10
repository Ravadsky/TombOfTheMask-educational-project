#pragma once
#include "ActorComponent.h"

enum class EMovementDirection
{
    Up,
    Down,
    Left,
    Right,
    NoDirection
};

class UMovementComponent : public UActorComponent
{
public:
    UMovementComponent(AActor* componentOwner);

    void Move(EMovementDirection direction);

private:
    EMovementDirection currentDirection = EMovementDirection::NoDirection;
    float movementSpeed = 8.0f;
};
