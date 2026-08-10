#include "InputComponent.h"
#include "GameStates/LevelSelector.h"
#include "MovementComponent.h"
#include "Actors/Actor.h"

UInputComponent::UInputComponent(AActor* componentOwner) : UActorComponent(componentOwner) {}

void UInputComponent::Update(float deltaTime)
{
    sf::Event event;
    while (Window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            Window->close();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            Engine->MarkToSwitchState<LevelSelector>();
        }
    }
    auto movementComponent = Owner->GetComponentByClass<UMovementComponent>();
    if (movementComponent != nullptr)
    {
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
            movementComponent->Move(currentDirection);
    }
}
