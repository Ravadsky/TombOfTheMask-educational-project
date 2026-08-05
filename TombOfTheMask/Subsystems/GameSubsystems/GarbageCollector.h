#pragma once
#include "UObject.h"

#include "VectorFunctions.h"

class Actor;

class GarbageCollector : public UObject
{
  public:
    std::vector<std::weak_ptr<Actor>> ActorsToKill;

    GarbageCollector();

    virtual void Update() override;
};
