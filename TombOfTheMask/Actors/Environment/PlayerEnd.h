#pragma once
#include "Actors/Actor.h"

class APlayerEnd : public AActor
{
public:
    APlayerEnd(UWorld* InWorld);

private:
    void EndLevel(UColliderComponent* otherCollider);
};
