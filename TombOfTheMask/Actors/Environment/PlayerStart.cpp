#include "PlayerStart.h"
#include "Components/ColliderComponent.h"
#include "Core/GameSubsystems/ResourceSubsystem.h"

APlayerStart::APlayerStart(UWorld* InWorld) : AActor(InWorld)
{
    ColliderComponent->SetCollisionPreset(ECollisionPreset::Ignore);

    SpriteComponent->SetSpriteTexture("player_start");
}