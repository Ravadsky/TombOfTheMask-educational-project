#include "Player.h"

#include "Components/ColliderComponent.h"
#include "Components/InputComponent.h"
#include "Components/MovementComponent.h"
#include "Components/CameraComponent.h"
#include "Components/ViewportComponent.h"
#include "Components/CameraShakeComponent.h"
#include "Core/GameSubsystems/AudioSubsystem.h"

#include "GameStates/LevelInstance.h"
#include "World/World.h"
#include "Actors/Effect.h"

APlayer::APlayer(UWorld* InWorld) : AActor(InWorld)
{
    bCanTick = true;

    InputComponent = AddNewComponent<UInputComponent>();
    MovementComponent = AddNewComponent<UMovementComponent>();
    CameraComponent = AddNewComponent<UCameraComponent>();

    ColliderComponent->SetCollisionPreset(ECollisionPreset::Block);
    ColliderComponent->onCollision.Add(this, &APlayer::StopMovement);
    ColliderComponent->SetWorldScale({ 0.7f, 0.7f });

    SpriteComponent->SetSpriteTexture("player");
    SpriteComponent->SetRenderLayer(ERenderLayer::medium);
    SpriteComponent->SetRotationIgnore();

    ViewportComponent = AddNewComponent<UViewportComponent>();

    CameraShakeComponent = AddNewComponent<UCameraShakeComponent>();
}

void APlayer::GetDamage()
{
    SpriteComponent->SetColor(sf::Color::Red);
    GetAudioSubsystem()->PlaySound("death");

    Engine->SetSleepingTime(500);

    GetWorld()->DestoyLevel();
    Engine->MarkToSwitchState<ULevelInstance>();
}

void APlayer::StopMovement(UColliderComponent* otherCollider)
{
    if (otherCollider->GetCollisionPreset() == ECollisionPreset::Block)
    {
        if (MovementComponent->WasRealMovement())
        {
            CameraShakeComponent->StartShake(0.5f, 4.0f);
            GetAudioSubsystem()->PlaySound("hit");

            
            auto effect = GetWorld()->SpawnActor<AEffect>(GetActorLocation(), GetActorRotation(), GetActorScale());
            effect->TriggerEffect("wall_hit_particle", false, 4);
        }

        MovementComponent->StopMovement(true);
        InputComponent->EnableControlActor();
    }
}