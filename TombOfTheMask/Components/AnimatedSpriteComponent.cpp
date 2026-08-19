#include "AnimatedSpriteComponent.h"
#include "Core/GameSubsystems/ResourceSubsystem.h"

UAnimatedSpriteComponent::UAnimatedSpriteComponent(AActor* componentOwner) : USpriteComponent(componentOwner) {}

void UAnimatedSpriteComponent::PlayAnimation(std::string animName, bool playLooping, int framesCount)
{
    bIsPlayed = true;

    currentAnimationFramesCount = framesCount;
    currentAnimationName = animName;
    bIsLoopingAnimation = playLooping;

    currentFrame = 0;
    currentTime = 0.0f;

    onAnimationStarted.Broadcast();
}

void UAnimatedSpriteComponent::EndAnimation()
{
    bIsPlayed = false;

    currentAnimationFramesCount = 0;
    currentAnimationName = "";
    bIsLoopingAnimation = false;

    currentFrame = 0;
    currentTime = 0.0f;

    onAnimationEnded.Broadcast();
}

void UAnimatedSpriteComponent::UpdateFrame()
{
    auto& texture = GetResourceSubsystem()->GetTexture(currentAnimationName);
    sf::IntRect frameRect(currentFrame * RAW_SPRITE_SIZE, 0, RAW_SPRITE_SIZE, RAW_SPRITE_SIZE);
    sprite.setTexture(texture);
    sprite.setTextureRect(frameRect);
}

void UAnimatedSpriteComponent::Update(float deltaTime)
{
    USpriteComponent::Update(deltaTime);

    if (bIsPlayed)
    {
        currentTime += deltaTime;

        if (currentTime >= frameRate)
        {
            currentTime -= frameRate;
            currentFrame++;

            if (currentFrame == currentAnimationFramesCount)
            {
                if (bIsLoopingAnimation)
                    currentFrame = 0;
                else
                {
                    EndAnimation();
                    return;
                }
            }

            UpdateFrame();
        }
    }
}
