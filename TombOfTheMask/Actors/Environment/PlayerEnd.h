#pragma once
#include "Actors/Actor.h"

class APlayerEnd : public AActor
{
public:
    APlayerEnd(UWorld* InWorld);

private:
    void EndLevel(UColliderComponent* otherCollider);
};

class APlayerEndBlock : public AActor
{
public:
    APlayerEndBlock(UWorld* InWorld);
};
