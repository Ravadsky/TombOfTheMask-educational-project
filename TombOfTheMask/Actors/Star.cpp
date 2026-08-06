#include "Star.h"
#include "Player.h"

#include "Components/ColliderComponent.h"
#include "Core/GameSubsystems/ResourceSubsystem.h"

AStar::AStar(UWorld* InWorld) : AActor(InWorld)
{
    ColliderComponent->SetCollisionPreset(ECollisionPreset::Overlap);
    ColliderComponent->onCollision.Add(this, &AStar::Pickup);

    auto& texture = GetResourceSubsystem()->GetTexture("star");
    SpriteComponent->SetSpriteTexture(texture);
    
}

void AStar::Pickup(UColliderComponent* otherCollider)
{
    auto actor = otherCollider->GetOwner();
    if (isClassOf<APlayer>(actor))
    {
        auto player = CastTo<APlayer>(actor);
        player->AddStar();
        MarkAsGarbage();
    }
}