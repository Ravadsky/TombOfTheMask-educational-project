#pragma once
#include "Components/ActorComponent.h"

class UMovementComponent;

class UInputComponent : public UActorComponent
{
public:
    UInputComponent(AActor* componentOwner);

    virtual void Update(float deltaTime) override;

    inline void EnableControlActor() { canControlActor = true; };
    inline void DisableControlActor() { canControlActor = false; };

private:
    UMovementComponent* movement;
    bool canControlActor = true;
};
