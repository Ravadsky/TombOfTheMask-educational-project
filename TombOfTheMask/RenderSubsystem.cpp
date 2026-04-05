#include "RenderSubsystem.h"
#include "SpriteComponent.h"
#include <ranges>

RenderSubsystem::RenderSubsystem()
{
}

void RenderSubsystem::BeginPlay()
{
}

void RenderSubsystem::Update()
{
    GWindow->clear(sf::Color(6, 6, 8, 255));

    auto StaticObjects =
        ObjectsToDraw | std::views::filter([](Drawable *Obj) { return Obj->Type == DrawType::Static; });

    for (auto Object : StaticObjects)
    {
        Object->Draw(*CameraPosition - CAMERA_PIVOT);
    }

    auto DynamicObjects =
        ObjectsToDraw | std::views::filter([](Drawable *Obj) { return Obj->Type == DrawType::Dynamic; });

    for (auto Object : DynamicObjects)
    {
        Object->Draw(*CameraPosition - CAMERA_PIVOT);
    }

    auto WidgetObjects =
        ObjectsToDraw | std::views::filter([](Drawable *Obj) { return Obj->Type == DrawType::Widget; });

    for (auto Object : WidgetObjects)
    {
        Object->Draw();
    }

    GWindow->display();
}

void RenderSubsystem::SetCameraPosition(sf::Vector2f *position)
{
    CameraPosition = position;
}
