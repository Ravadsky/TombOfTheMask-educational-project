#pragma once
#include "Actors/Actor.h"

class ASpikes : public AActor
{
public:
    ASpikes(UWorld* InWorld);

    private:
    void DamagePlayer(UColliderComponent* otherCollider);
};
