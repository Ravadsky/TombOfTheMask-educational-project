#pragma once
#include "CoreMinimal.h"


class UObject
{
public:
	virtual void BeginPlay() = 0;

	virtual void Update() = 0;
};

