#pragma once
#include "UObject.h"

class GameState : public UObject
{
  public:
    virtual ~GameState() = default;
    virtual void BeginPlay() override;
};
