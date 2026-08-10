#include "UserWidget.h"
#include "Core/GameSubsystems/RenderSubsystem.h"

UUserWidget::UUserWidget()
{
    GetRenderSubsystem()->WidgetsToDraw.push_back(this);
};

UUserWidget::~UUserWidget()
{
    RemoveFromVectorByRef(GetRenderSubsystem()->WidgetsToDraw, this);
}
