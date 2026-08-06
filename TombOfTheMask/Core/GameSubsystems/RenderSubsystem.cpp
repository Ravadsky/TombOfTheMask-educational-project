#include "RenderSubsystem.h"

#include "Widgets/Drawable.h"
#include "Components/SpriteComponent.h"
#include <ranges>

URenderSubsystem::URenderSubsystem() : UGameSubsystem() {}

void URenderSubsystem::Update(float deltaTime)
{
    Window->clear(WindowColor);

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

    Window->display();
}

void URenderSubsystem::SetCameraPosition(sf::Vector2f* position)
{
    CameraPosition = position;
}

void URenderSubsystem::ClearObjectsToDraw()
{
    ObjectsToDraw.clear();
}
