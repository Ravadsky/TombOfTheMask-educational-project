#include "Player.h"

#include "Components/ColliderComponent.h"
#include "Components/InputComponent.h"
#include "Components/MovementComponent.h"
#include "Components/CameraComponent.h"
#include "Components/ViewportComponent.h"
#include "Core/GameSubsystems/AudioSubsystem.h"

#include "Actors/Environment/Archer.h"
#include "GameStates/LevelInstance.h"
#include "World/World.h"

APlayer::APlayer(UWorld* InWorld) : AActor(InWorld)
{
    bCanTick = true;

    MovementComponent = AddNewComponent<UMovementComponent>();
    InputComponent = AddNewComponent<UInputComponent>();
    CameraComponent = AddNewComponent<UCameraComponent>();

    ColliderComponent->SetCollisionPreset(ECollisionPreset::Block);
    ColliderComponent->onCollision.Add(this, &APlayer::StopMovement);

    SpriteComponent->SetSpriteTexture("player");

    ViewportComponent = AddNewComponent<UViewportComponent>();


    // CollisionBox = { position.x - SPRITE_GAME_SIZE / 4, position.y - SPRITE_GAME_SIZE / 4, SPRITE_GAME_SIZE / 2,
    //                  SPRITE_GAME_SIZE / 2 };
}

// sf::FloatRect APlayer::GetCollisionBox()
//{
//
//     float TempWidth = SPRITE_GAME_SIZE / 2;
//     float TempHeight = SPRITE_GAME_SIZE / 2;
//     float TempLeft = ActorLocation.x - SPRITE_GAME_SIZE / 4 + (PlayerDirection.x * SPRITE_GAME_SIZE / 4);
//     float TempTop = ActorLocation.y - SPRITE_GAME_SIZE / 4 + (PlayerDirection.y * SPRITE_GAME_SIZE / 4);
//
//     return { TempLeft, TempTop, TempWidth, TempHeight };
// }

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
        MovementComponent->StopMovement(true);
        InputComponent->EnableControlActor();
    }
}
