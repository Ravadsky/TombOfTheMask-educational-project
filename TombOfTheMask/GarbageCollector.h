#pragma once
#include "UObject.h"
#include <vector>

class Actor;

class GarbageCollector :
    public UObject
{
public:
	std::vector<std::weak_ptr<Actor>> ActorsToKill;

	GarbageCollector();
	void BeginPlay() override;
	void Update() override;
};

