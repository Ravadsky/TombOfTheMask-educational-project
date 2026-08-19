#pragma once
#include "SpriteComponent.h"
class UAnimatedSpriteComponent : public USpriteComponent
{
private:
    const float frameRate = 0.333f;
    int currentFrame = 0;
    float currentTime = 0.0f;
    bool bIsPlayed = false;

    std::string currentAnimationName;
    int currentAnimationFramesCount;
    bool bIsLoopingAnimation;

public:
    UAnimatedSpriteComponent(AActor* componentOwner);

    void PlayAnimation(std::string animName, bool playLooping, int framesCount = 6);
    void EndAnimation();
    void UpdateFrame();

    virtual void Update(float deltaTime) override;

    FDelegate<> onAnimationStarted;
    FDelegate<> onAnimationEnded;
};
