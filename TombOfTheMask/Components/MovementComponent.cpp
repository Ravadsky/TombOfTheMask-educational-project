#include "MovementComponent.h"
#include "Actors/Actor.h"

UMovementComponent::UMovementComponent(AActor* componentOwner) : UActorComponent(componentOwner) {}

void UMovementComponent::Move(EMovementDirection direction)
{
    sf::Vector2f vectorDirection;

    switch (direction)
    {
        case EMovementDirection::Up:
            vectorDirection = { 0.f, -1.f };
            // ActorSprite->SetRotation(90.f);
            // ActorSprite->Flip(true);
            break;
        case EMovementDirection::Down:
            vectorDirection = { 0.f, 1.f };
            //  ActorSprite->SetRotation(90.f);
            //   ActorSprite->Flip(false);
            break;
        case EMovementDirection::Left:
            vectorDirection = { -1.f, 0.f };
            //    ActorSprite->SetRotation(0.f);
            //   ActorSprite->Flip(true);
            break;
        case EMovementDirection::Right:
            vectorDirection = { 1.f, 0.f };
            // ActorSprite->SetRotation(0.f);
            //   ActorSprite->Flip(false);
            break;

        case EMovementDirection::NoDirection:
            vectorDirection = { 0.f, 0.f };
    }

    sf::Vector2f OffsetInPixels(vectorDirection.x * movementSpeed, vectorDirection.y * movementSpeed);
    GetOwner()->AddWorldOffset(OffsetInPixels);
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
}
