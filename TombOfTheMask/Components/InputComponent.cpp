#include "InputComponent.h"
#include "MovementComponent.h"
#include "Actors/Actor.h"
#include "World/World.h"

UInputComponent::UInputComponent(AActor* componentOwner) : UActorComponent(componentOwner) {}

void UInputComponent::Update(float deltaTime)
{
    if (canControlActor == false)
        return;

    movement = Owner->GetComponentByClass<UMovementComponent>();
    assert(movement != nullptr);

    EMovementDirection currentDirection = EMovementDirection::NoDirection;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        currentDirection = EMovementDirection::Up;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        currentDirection = EMovementDirection::Down;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        currentDirection = EMovementDirection::Left;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        currentDirection = EMovementDirection::Right;

    if (currentDirection != EMovementDirection::NoDirection)
    {
        if (GetOwner()->GetWorld()->bIsEditorMode == false)
            canControlActor = false;

        movement->Move(currentDirection, true);
    }
}
