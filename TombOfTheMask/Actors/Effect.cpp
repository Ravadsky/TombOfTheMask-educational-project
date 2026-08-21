#include "Effect.h"

#include "Components/ColliderComponent.h"
#include "Components/AnimatedSpriteComponent.h"

AEffect::AEffect(UWorld* InWorld) : AActor(InWorld)
{
    bCanTick = true;

    animatedSpriteComponent = AddNewComponent<UAnimatedSpriteComponent>();
    animatedSpriteComponent->AttachToComponent(SceneComponent);
    animatedSpriteComponent->SetRenderLayer(ERenderLayer::forward);
}

void AEffect::TriggerEffect(std::string effectName, bool isLooping, int framesCount)
{
    bIsLoopingEffect = isLooping;
    animatedSpriteComponent->PlayAnimation(effectName, bIsLoopingEffect, 4);

    if (!bIsLoopingEffect)
        animatedSpriteComponent->onAnimationEnded.Add(this, &AEffect::DestroyEffect);
}

void AEffect::DestroyEffect()
{
    MarkAsGarbage();
}

void AEffect::Update(float deltaTime)
{
    AActor::Update(deltaTime);
}

void AEffect::BeginPlay()
{
    AActor::BeginPlay();
}
