#include "UserWidget.h"
#include "Core/GameSubsystems/RenderSubsystem.h"

sf::Vector2f UUserWidget::GetAlignmentOffset()
{
    sf::Vector2f offset(0, 0);

    switch (horizontalAlignment)
    {
        case EHorizontalAlignment::Left:
            offset.x = 0;
            break;
        case EHorizontalAlignment::Center:
            offset.x = WINDOW_WIGHT / 2;
            break;
        case EHorizontalAlignment::Right:
            offset.x = WINDOW_WIGHT;
            break;
    }
    switch (verticalAlignment)
    {
        case EVerticalAlignment::Top:
            offset.y = 0;
            break;
        case EVerticalAlignment::Center:
            offset.y = WINDOW_HEIGHT / 2;
            break;
        case EVerticalAlignment::Bottom:
            offset.y = WINDOW_HEIGHT;
            break;
    }
    return offset;
}

UUserWidget::UUserWidget(UUserWidget* parent)
{
    parentWidget = parent;
    GetRenderSubsystem()->WidgetsToDraw.push_back(this);
};

UUserWidget::~UUserWidget()
{
    RemoveFromVectorByRef(GetRenderSubsystem()->WidgetsToDraw, this);
}

sf::Vector2f UUserWidget::GetScreenPosition()
{
    if (parentWidget != nullptr)
        return screenPosition + parentWidget->GetScreenPosition();
    else
        return screenPosition;
}

void UUserWidget::SetAlignment(EHorizontalAlignment horizontal, EVerticalAlignment vertical)
{
    horizontalAlignment = horizontal;
    verticalAlignment = vertical;
}
