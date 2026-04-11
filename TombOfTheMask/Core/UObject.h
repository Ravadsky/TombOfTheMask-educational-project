#pragma once
#include "CoreMinimal.h"

class UObject
{
  protected:
    bool canTick = false;

  public:
    virtual void BeginPlay();

    virtual void Update();

    bool CanTick();
};
