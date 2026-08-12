#pragma once
#include "Actors/Actor.h"

class AStar : public AActor
{
public:
    AStar(UWorld* InWorld);

private:
    void Pickup(UColliderComponent* otherCollider);
};
