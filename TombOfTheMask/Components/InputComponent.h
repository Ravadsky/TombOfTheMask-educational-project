#pragma once
#include "Components/ActorComponent.h"

class UInputComponent : public UActorComponent
{
public:
    UInputComponent(AActor* componentOwner);

    virtual void Update(float deltaTime) override;
};
