#include "Archer.h"
#include "Arrow.h"

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

    timer += deltaTime;
    if (timer > 1.6f)
    {
        timer -= 1.6f;

        sf::Vector2f ArrowOffset = RotateVector({ SPRITE_GAME_SIZE, 0.f }, GetActorRotation() );

        GetWorld()->SpawnActor<AArrow>(GetActorLocation() + ArrowOffset, GetActorRotation(), GetActorScale());
        GetAudioSubsystem()->PlaySound("archer_sound");
    }
}
