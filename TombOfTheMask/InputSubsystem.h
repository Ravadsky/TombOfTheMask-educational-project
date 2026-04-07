#pragma once
#include "UObject.h"

class InputSubsystem : public UObject
{
  public:
    InputSubsystem();
    void Update() override;
};
