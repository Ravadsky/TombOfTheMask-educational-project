#pragma once
#include "Actors/Actor.h"

class UAnimatedSpriteComponent;

class AStar : public AActor
{
public:
    AStar(UWorld* InWorld);

private:
    void Pickup(UColliderComponent* otherCollider);

    UAnimatedSpriteComponent* animatedSpriteComponent;

    void Destroy();
    bool bIsPickuped = false;
};
