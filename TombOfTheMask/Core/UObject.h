#pragma once
#include "CoreMinimal.h"

class UObject
{
protected:
    bool bCanTick = false;

public:
    virtual void BeginPlay() {};

    virtual void Update() {};

    inline bool CanTick() const { return bCanTick; }
};
