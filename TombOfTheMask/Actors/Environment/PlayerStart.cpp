#include "PlayerStart.h"
#include "Components/ColliderComponent.h"
#include "Core/GameSubsystems/ResourceSubsystem.h"
#include "World/World.h"
#include "Actors/Player.h"

APlayerStart::APlayerStart(UWorld* InWorld) : AActor(InWorld)
{
    ColliderComponent->SetCollisionPreset(ECollisionPreset::Ignore);

    SpriteComponent->SetSpriteTexture("player_start");
}

void APlayerStart::BeginPlay()
{
    if (GetWorld()->bIsEditorMode == false)
        GetWorld()->SpawnActor<APlayer>(GetActorLocation(), GetActorRotation(), GetActorScale());
}

APlayerStartBlock::APlayerStartBlock(UWorld* InWorld) : AActor(InWorld)
{
    ColliderComponent->SetCollisionPreset(ECollisionPreset::Block);

    SpriteComponent->SetSpriteTexture("player_start_block");
}
