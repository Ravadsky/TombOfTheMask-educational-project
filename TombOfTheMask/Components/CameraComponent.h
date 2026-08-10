#pragma once
#include "ActorComponent.h"

class UCameraComponent : public UActorComponent
{
public:
    UCameraComponent(AActor* componentOwner);
    virtual ~UCameraComponent();
};
