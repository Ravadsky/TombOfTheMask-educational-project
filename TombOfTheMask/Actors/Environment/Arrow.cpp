#include "Arrow.h"

#include "Actors/Player.h"
#include "Components/ColliderComponent.h"
#include "Core/GameSubsystems/ResourceSubsystem.h"

AArrow::AArrow(UWorld* InWorld) : AActor(InWorld)
{
    bCanTick = true;

    ColliderComponent->SetCollisionPreset(ECollisionPreset::Overlap);
    ColliderComponent->onCollision.Add(this, &AArrow::DamageTarget);

    MovementComponent = AddNewComponent<UMovementComponent>();

    SpriteComponent->SetSpriteTexture("arrow");
}

void AArrow::DamageTarget(UColliderComponent* otherCollider)
{
    if (otherCollider->GetCollisionPreset() == ECollisionPreset::Block)
    {
        auto actor = otherCollider->GetOwner();
        if (isClassOf<APlayer>(actor))
        {
            auto player = CastTo<APlayer>(actor);
            player->GetDamage();
        }
        MarkAsGarbage();
    }
}

void AArrow::Update(float deltaTime)
{
    MovementComponent->Move(InitialDirection);

    // CollisionBox = { ActorLocation.x - SPRITE_GAME_SIZE / 4, ActorLocation.y - SPRITE_GAME_SIZE / 4,
    //                  SPRITE_GAME_SIZE / 2, SPRITE_GAME_SIZE / 2 };
    // ActorSprite->SetPosition(ActorLocation);
}

void AArrow::BeginPlay() {}