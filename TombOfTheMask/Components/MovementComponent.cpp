#include "MovementComponent.h"
#include "ColliderComponent.h"
#include "Actors/Actor.h"
#include "World/World.h"

UMovementComponent::UMovementComponent(AActor* componentOwner) : UActorComponent(componentOwner)
{
    bCanTick = true;
}

void UMovementComponent::Move(EMovementDirection direction, bool isPushing)
{

    bIsPushing = isPushing;
    currentDirection = direction;

    sprite = GetOwner()->GetComponentByClass<USpriteComponent>();

    switch (currentDirection)
    {
        case EMovementDirection::Up:
            SetMovement({ 0.f, -movementSpeed }, 270.0f, false);
            break;
        case EMovementDirection::Down:
            SetMovement({ 0.f, movementSpeed }, 90.0f, false);
            break;
        case EMovementDirection::Left:
            SetMovement({ -movementSpeed, 0.f }, 180.0f, true);
            break;
        case EMovementDirection::Right:
            SetMovement({ movementSpeed, 0.f }, 0.0f, false);
            break;

        case EMovementDirection::NoDirection:
            SetMovement({ 0, 0.f }, 0.0f, false);
    }
    GetOwner()->AddWorldOffset(lastMovementOffset);
    movedDistance += Length(lastMovementOffset);
    
    
}

void UMovementComponent::StopMovement(bool revertPreviousMovement)
{
    bIsPushing = false;
    currentDirection = EMovementDirection::NoDirection;
    movedDistance = 0.0f;

    if (revertPreviousMovement)
        GetOwner()->AddWorldOffset(-lastMovementOffset);
}

void UMovementComponent::Update(float deltaTime)
{
    if (GetOwner()->GetWorld()->bIsEditorMode == false)
        if (bIsPushing)
            Move(currentDirection, true);
}

void UMovementComponent::SetMovement(sf::Vector2f direction, float spriteRotation, bool spriteFlip)
{

    lastMovementOffset = direction;
    GetOwner()->SetActorRotation(spriteRotation);
    //sprite->SetWorldRotation(spriteRotation);
    sprite->Flip(spriteFlip);
}

bool isRotationApproximatelyEqual(float rotation, float equals, float threshold)
{
    return ((rotation > equals - threshold) and (rotation < equals + threshold));
}

EMovementDirection ConvertDirectionFromRotation(float rotation)
{
    if (isRotationApproximatelyEqual(rotation, 0.0f))
        return EMovementDirection::Right;
    if (isRotationApproximatelyEqual(rotation, 90.0f))
        return EMovementDirection::Down;
    if (isRotationApproximatelyEqual(rotation, 180.0f))
        return EMovementDirection::Left;
    if (isRotationApproximatelyEqual(rotation, 270.0f))
        return EMovementDirection::Up;

    return EMovementDirection::NoDirection;
}
