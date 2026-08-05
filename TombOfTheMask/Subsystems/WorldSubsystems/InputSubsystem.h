#pragma once
#include "UObject.h"

class InputSubsystem : public UObject
{
  public:
    InputSubsystem();

    virtual void Update() override;
};
