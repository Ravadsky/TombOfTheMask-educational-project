#pragma once
#include "CoreMinimal.h"

class UObject
{
protected:
    bool bCanTick = false;

public:
    UObject();
    virtual ~UObject();

    virtual void BeginPlay() {};
    virtual void Update() {};

    void MarkAsGarbage();

    inline bool CanTick() const { return bCanTick; }
};
