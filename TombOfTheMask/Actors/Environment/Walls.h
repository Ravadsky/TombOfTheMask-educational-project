#pragma once
#include "Actors/Actor.h"

class AWall : public AActor
{
public:
    AWall(UWorld* InWorld);
};

class ACornerWall : public AActor
{
public:
    ACornerWall(UWorld* InWorld);
};

class ABackgroundWall : public AActor
{
public:
    ABackgroundWall(UWorld* InWorld);
};
