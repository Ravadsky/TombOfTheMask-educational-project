#pragma once
#include "Core/UObject.h"

class AActor;

class UActorComponent : public UObject
{
public:
    UActorComponent() = delete;
    UActorComponent(AActor* componentOwner);

    inline AActor* GetOwner() { return Owner; };

    protected:
    AActor* Owner;
};
