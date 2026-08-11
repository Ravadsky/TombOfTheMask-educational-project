#include "RenderSubsystem.h"

#include "Components/CameraComponent.h"
#include "Components/SpriteComponent.h"
#include <ranges>
#include "Actors/Actor.h"
#include "GUI/Base/UserWidget.h"

URenderSubsystem::URenderSubsystem() : UGameSubsystem() {}

void URenderSubsystem::Update(float deltaTime)
{
    Window->clear(WindowColor);

    if (CurrentCameraComponent != nullptr)
        CameraOrigin = CurrentCameraComponent->GetCameraPosition();
    else
        CameraOrigin = { 0.0f, 0.0f };

    // render back objects
    auto isBack = [](USpriteComponent* Obj) { return Obj->GetRenderLayer() == ERenderLayer::back; };
    auto back_objects = ActorsToDraw | std::views::filter(isBack);

    for (auto object : back_objects)
        object->Render(CameraOrigin);

    // render medium objects
    auto isMedium = [](USpriteComponent* Obj) { return Obj->GetRenderLayer() == ERenderLayer::medium; };
    auto medium_objects = ActorsToDraw | std::views::filter(isMedium);

    for (auto object : medium_objects)
        object->Render(CameraOrigin);

    // render front objects
    auto isForward = [](USpriteComponent* Obj) { return Obj->GetRenderLayer() == ERenderLayer::forward; };
    auto forward_objects = ActorsToDraw | std::views::filter(isForward);

    for (auto object : forward_objects)
        object->Render(CameraOrigin);

    // widgets
    for (auto widget : WidgetsToDraw)
        widget->Render();

    Window->display();
}
