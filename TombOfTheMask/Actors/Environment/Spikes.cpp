#include "Spikes.h"

#include "Actors/Player.h"

#include "Components/ColliderComponent.h"
#include "Core/GameSubsystems/ResourceSubsystem.h"

ASpikes::ASpikes(UWorld* InWorld) : AActor(InWorld)
{
    ColliderComponent->SetCollisionPreset(ECollisionPreset::Block);
    ColliderComponent->onCollision.Add(this, &ASpikes::DamagePlayer);

    SpriteComponent->SetSpriteTexture("spikes");
}

void ASpikes::DamagePlayer(UColliderComponent* otherCollider)
{
    auto actor = otherCollider->GetOwner();

    if (isClassOf<APlayer>(actor))
    {
        auto player = CastTo<APlayer>(actor);
        player->GetDamage();
    }
}
