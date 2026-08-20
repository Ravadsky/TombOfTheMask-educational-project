#include "Effect.h"

#include "Components/ColliderComponent.h"
#include "Components/AnimatedSpriteComponent.h"

AEffect::AEffect(UWorld* InWorld) : AActor(InWorld)
{
    ColliderComponent->SetCollisionPreset(ECollisionPreset::Ignore);

    animatedSpriteComponent = AddNewComponent<UAnimatedSpriteComponent>();
    animatedSpriteComponent->AttachToComponent(SceneComponent);
}

void AEffect::TriggerEffect(std::string effectName, bool isLooping)
{
    bIsLoopingEffect = isLooping;
    animatedSpriteComponent->PlayAnimation(effectName, bIsLoopingEffect);

    if (bIsLoopingEffect)
        animatedSpriteComponent->onAnimationEnded.Add(this, &AEffect::DestroyEffect);
}

void AEffect::DestroyEffect()
{
    MarkAsGarbage();
}
