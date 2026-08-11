#include "Point.h"
#include "Player.h"

#include "Components/ColliderComponent.h"
#include "Components/ViewportComponent.h"
#include "Core/GameSubsystems/ResourceSubsystem.h"
#include "World/World.h"

APoint::APoint(UWorld* InWorld) : AActor(InWorld)
{
    ColliderComponent->SetCollisionPreset(ECollisionPreset::Overlap);
    ColliderComponent->onCollision.Add(this, &APoint::Pickup);

    SpriteComponent->SetSpriteTexture("star");
}

void APoint::Pickup(UColliderComponent* otherCollider)
{
    auto actor = otherCollider->GetOwner();
    if (isClassOf<APlayer>(actor))
    {
        auto viewport = actor->GetComponentByClass<UViewportComponent>();
        viewport->AddPoint();
        MarkAsGarbage();
    }
}