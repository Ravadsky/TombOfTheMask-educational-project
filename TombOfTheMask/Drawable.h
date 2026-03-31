#pragma once
#include "CoreMinimal.h"

class Drawable
{
public:

	virtual void Draw() = 0;

	Drawable();
	~Drawable();
};