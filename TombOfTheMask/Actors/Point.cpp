#include "Point.h"
#include "Player.h"

#include "Components/ColliderComponent.h"
#include "Core/GameSubsystems/ResourceSubsystem.h"

APoint::APoint(UWorld* InWorld) : AActor(InWorld)
{
    ColliderComponent->SetCollisionPreset(ECollisionPreset::Overlap);
    ColliderComponent->onCollision.Add(this, &APoint::Pickup);

    auto& texture = GetResourceSubsystem()->GetTexture("star");
    SpriteComponent->SetSpriteTexture(texture);
}

void APoint::Pickup(UColliderComponent* otherCollider)
{
    auto actor = otherCollider->GetOwner();
    if (isClassOf<APlayer>(actor))
    {
        auto player = CastTo<APlayer>(actor);
        player->AddPoint();
        MarkAsGarbage();
    }
}