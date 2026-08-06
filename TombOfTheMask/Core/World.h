#pragma once
#include "UObject.h"

class AActor;

class UWorld : public UObject
{
private:
    std::vector<AActor*> ActorsInWorld;
};
