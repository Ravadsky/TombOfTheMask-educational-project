#pragma once
#include "GameSubsystem.h"

class UGarbageCollector : public UGameSubsystem
{
public:
    UGarbageCollector();

    virtual void Update(float deltaTime) override;

    void AddObjectToKill(UObject* object);

private:
    std::vector<UObject*> ObjectsToKill;
};
