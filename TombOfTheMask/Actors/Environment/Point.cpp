#include "Point.h"
#include "Actors/Player.h"

#include "Components/ColliderComponent.h"
#include "Components/ViewportComponent.h"
#include "World/World.h"

APoint::APoint(UWorld* InWorld) : AActor(InWorld)
{
    ColliderComponent->SetCollisionPreset(ECollisionPreset::Overlap);
    ColliderComponent->SetWorldScale({ 0.5f, 0.5f });
    ColliderComponent->onCollision.Add(this, &APoint::Pickup);

    SpriteComponent->SetSpriteTexture("point");
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