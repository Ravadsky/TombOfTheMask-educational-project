#pragma once
#include "CoreMinimal.h"

class UObject
{
  protected:
    bool canTick = false;

  public:
    virtual void BeginPlay() = 0;

    virtual void Update() = 0;

    bool CanTick();
};
