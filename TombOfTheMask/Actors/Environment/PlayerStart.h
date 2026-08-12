#pragma once
#include "Actors/Actor.h"

class APlayerStart : public AActor
{
public:
    APlayerStart(UWorld* InWorld);

    virtual void BeginPlay() override;
};

class APlayerStartBlock : public AActor
{
public:
    APlayerStartBlock(UWorld* InWorld);
};