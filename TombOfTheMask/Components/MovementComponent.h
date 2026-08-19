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

class USpriteComponent;

class UMovementComponent : public UActorComponent
{
public:
    UMovementComponent(AActor* componentOwner);

    void Move(EMovementDirection direction, bool isPushing = false);
    void StopMovement(bool revertPreviousMovement = false);

    virtual void Update(float deltaTime) override;

private:
    const float movementSpeed = 8.0f;

    USpriteComponent* sprite;
    EMovementDirection currentDirection = EMovementDirection::NoDirection;
    sf::Vector2f lastMovementOffset;
    bool bIsPushing = false;

    void SetMovement(sf::Vector2f direction, float spriteRotation, bool spriteFlip);
};

bool isRotationApproximatelyEqual(float rotation, float equals, float threshold = 1.0f);
EMovementDirection ConvertDirectionFromRotation(float rotation);