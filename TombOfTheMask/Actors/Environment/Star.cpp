#include "Star.h"
#include "Actors/Player.h"

#include "Components/ColliderComponent.h"
#include "Components/ViewportComponent.h"
#include "Components/AnimatedSpriteComponent.h"
#include "Core/GameSubsystems/ResourceSubsystem.h"
#include "World/World.h"

AStar::AStar(UWorld* InWorld) : AActor(InWorld)
{
    ColliderComponent->SetCollisionPreset(ECollisionPreset::Overlap);
    ColliderComponent->SetWorldScale({ 0.5f, 0.5f });
    ColliderComponent->onCollision.Add(this, &AStar::Pickup);

    animatedSpriteComponent = AddNewComponent<UAnimatedSpriteComponent>();
    animatedSpriteComponent->AttachToComponent(SceneComponent);

    animatedSpriteComponent->PlayAnimation("star_idle", true);
}

void AStar::Pickup(UColliderComponent* otherCollider)
{
    if (bIsPickuped)
        return;

    auto actor = otherCollider->GetOwner();

    if (isClassOf<APlayer>(actor))
    {
        auto viewport = actor->GetComponentByClass<UViewportComponent>();
        animatedSpriteComponent->PlayAnimation("star_pickup", false);
        animatedSpriteComponent->onAnimationEnded.Add(this, &AStar::Destroy);
        viewport->AddStar();
        bIsPickuped = true;
    }
}

void AStar::Destroy()
{
    MarkAsGarbage();
}
