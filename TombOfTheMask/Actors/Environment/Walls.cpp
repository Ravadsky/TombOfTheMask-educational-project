#include "Walls.h"
#include "Components/ColliderComponent.h"
#include "Core/GameSubsystems/ResourceSubsystem.h"

AWall::AWall(UWorld* InWorld) : AActor(InWorld)
{
    ColliderComponent->SetCollisionPreset(ECollisionPreset::Block);

    SpriteComponent->SetSpriteTexture("wall");
    SpriteComponent->SetRenderLayer(ERenderLayer::medium);
}

ACornerWall::ACornerWall(UWorld* InWorld) : AActor(InWorld)
{
    ColliderComponent->SetCollisionPreset(ECollisionPreset::Block);

    SpriteComponent->SetSpriteTexture("corner_wall");
    SpriteComponent->SetRenderLayer(ERenderLayer::medium);
}

ABackgroundWall::ABackgroundWall(UWorld* InWorld) : AActor(InWorld)
{
    ColliderComponent->SetCollisionPreset(ECollisionPreset::Ignore);

    SpriteComponent->SetSpriteTexture("background_wall");
    SpriteComponent->SetRenderLayer(ERenderLayer::back);
}