#include "Spikes.h"

#include "Actors/Player.h"

#include "Components/ColliderComponent.h"
#include "Components/AnimatedSpriteComponent.h"

ASpikes::ASpikes(UWorld* InWorld) : AActor(InWorld)
{
    ColliderComponent->SetCollisionPreset(ECollisionPreset::Block);
    ColliderComponent->onCollision.Add(this, &ASpikes::DamagePlayer);
    ColliderComponent->SetWorldScale({ 0.8f, 0.8f });

    animatedSpriteComponent = AddNewComponent<UAnimatedSpriteComponent>();
    animatedSpriteComponent->AttachToComponent(SceneComponent);
    animatedSpriteComponent->PlayAnimation("spikes_idle", true);
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
