#pragma once
#include "CoreMinimal.h"

enum class DrawType
{
	Static,
	Dynamic,
	Widget,
};

class Drawable
{
public:
	DrawType Type = DrawType::Static;

	virtual void Draw(sf::Vector2f position) = 0;

	Drawable();
	~Drawable();
};