#include "PhysicsSubsystem.h"

#include "Components/ColliderComponent.h"
#include "Actors/Actor.h"

void UPhysicsSubsystem::Update(float deltaTime)
{
    for (auto component : triggerComponents)
    {
        if (component->GetCollisionPreset() == ECollisionPreset::Ignore)
            continue;

        for (auto otherComponent : triggerComponents)
        {
            if (component == otherComponent)
                continue;

            if (otherComponent->GetCollisionPreset() == ECollisionPreset::Ignore)
                continue;

            if (component->GetCollisionBox().intersects(otherComponent->GetCollisionBox()))
            {
                if (component->GetOwner()->IsValid())
                    component->OnCollision(otherComponent);

                if (otherComponent->GetOwner()->IsValid())
                    otherComponent->OnCollision(component);
            }
        }
    }
}

void UPhysicsSubsystem::AddTriggerComponent(UColliderComponent* component)
{
    triggerComponents.push_back(component);
}

void UPhysicsSubsystem::RemoveTriggerComponent(UColliderComponent* component)
{
    auto objectIterator = std::find(triggerComponents.begin(), triggerComponents.end(), component);
    if (objectIterator != triggerComponents.end())
        triggerComponents.erase(objectIterator);
}
