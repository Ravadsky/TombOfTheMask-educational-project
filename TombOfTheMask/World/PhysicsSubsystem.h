#pragma once
#include "Core/UObject.h"

class UColliderComponent;

class UPhysicsSubsystem : public UObject
{
public:
    virtual void Update(float deltaTime) override;

    void AddTriggerComponent(UColliderComponent* component);
    void RemoveTriggerComponent(UColliderComponent* component);

private:
    std::vector<UColliderComponent*> triggerComponents;
};
