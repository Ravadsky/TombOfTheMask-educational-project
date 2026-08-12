#include "Star.h"
#include "Actors/Player.h"

#include "Components/ColliderComponent.h"
#include "Components/ViewportComponent.h"
#include "Core/GameSubsystems/ResourceSubsystem.h"
#include "World/World.h"

AStar::AStar(UWorld* InWorld) : AActor(InWorld)
{
    ColliderComponent->SetCollisionPreset(ECollisionPreset::Overlap);
    ColliderComponent->onCollision.Add(this, &AStar::Pickup);

    SpriteComponent->SetSpriteTexture("star");
}

void AStar::Pickup(UColliderComponent* otherCollider)
{
    auto actor = otherCollider->GetOwner();

    if (isClassOf<APlayer>(actor))
    {
        auto viewport = actor->GetComponentByClass<UViewportComponent>();
        viewport->AddStar();
        MarkAsGarbage();
    }
}