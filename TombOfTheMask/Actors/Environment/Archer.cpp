#include "Archer.h"
#include "Actors/Player.h"

#include "Core/GameSubsystems/AudioSubsystem.h"
#include "Components/ColliderComponent.h"
#include "Core/GameSubsystems/ResourceSubsystem.h"
#include "World/World.h"

AArcher::AArcher(UWorld* InWorld) : AActor(InWorld)
{
    bCanTick = true;

    ColliderComponent->SetCollisionPreset(ECollisionPreset::Block);

    SpriteComponent->SetSpriteTexture("archer");
}

void AArcher::Update(float deltaTime)
{
    AActor::Update(deltaTime);

    if (GetWorld()->bIsEditorMode == false)
    {
        timer += deltaTime;
        if (timer > 1.6f)
        {
            timer -= 1.6f;

            sf::Vector2f ArrowOffset = RotateVector({ SPRITE_GAME_SIZE, 0.f }, GetActorRotation());

            auto arrow =
                GetWorld()->SpawnActor<AArrow>(GetActorLocation() + ArrowOffset, GetActorRotation(), { 0.3f, 0.3f });

            arrow->SetInitialDirection(ConvertDirectionFromRotation(GetActorRotation()));

            GetAudioSubsystem()->PlaySound("archer");
        }
    }
}

// archer projectile

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
    AActor::Update(deltaTime);

    MovementComponent->Move(InitialDirection);

    // CollisionBox = { ActorLocation.x - SPRITE_GAME_SIZE / 4, ActorLocation.y - SPRITE_GAME_SIZE / 4,
    //                  SPRITE_GAME_SIZE / 2, SPRITE_GAME_SIZE / 2 };
    // ActorSprite->SetPosition(ActorLocation);
}

void AArrow::BeginPlay() {}

void AArrow::SetInitialDirection(EMovementDirection direction)
{
    InitialDirection = direction;
}
