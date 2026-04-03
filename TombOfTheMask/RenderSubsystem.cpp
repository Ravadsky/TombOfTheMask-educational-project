#include "RenderSubsystem.h"
#include <ranges>
#include "SpriteComponent.h"

RenderSubsystem::RenderSubsystem()
{
}

void RenderSubsystem::BeginPlay()
{
}

void RenderSubsystem::Update()
{
	GWindow->clear(sf::Color(6, 6, 8, 255));

	auto StaticObjects = ObjectsToDraw
		| std::views::filter([](Drawable* Obj) {return Obj->Type == DrawType::Static; });

	for (auto Object : StaticObjects)
	{
		Object->Draw();
	}

	auto DynamicObjects = ObjectsToDraw
		| std::views::filter([](Drawable* Obj) {return Obj->Type == DrawType::Dynamic; });

	for (auto Object : DynamicObjects)
	{
		Object->Draw();
	}

	auto WidgetObjects = ObjectsToDraw
		| std::views::filter([](Drawable* Obj) {return Obj->Type == DrawType::Widget; });

	for (auto Object : WidgetObjects)
	{
		Object->Draw();
	}

	GWindow->display();
}
