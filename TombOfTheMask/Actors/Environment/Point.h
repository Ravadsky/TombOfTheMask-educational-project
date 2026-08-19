#pragma once
#include "Actors/Actor.h"

class APoint : public AActor
{
public:
    APoint(UWorld* InWorld);

private:
    void Pickup(UColliderComponent* otherCollider);
};
