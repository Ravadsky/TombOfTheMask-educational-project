#pragma once
#include "Actor.h"

#include "GUI/UserWidget.h"

class UInputComponent;
class UMovementComponent;
class UCameraComponent;

class APlayer : public AActor
{
public:
    APlayer(UWorld* InWorld);

    virtual void BeginPlay() override;
    virtual void Update(float deltaTime) override;

    sf::FloatRect GetCollisionBox();

    void GetDamage();

private:
    UInputComponent* InputComponent;
    UMovementComponent* MovementComponent;
    UCameraComponent* CameraComponent;
};
