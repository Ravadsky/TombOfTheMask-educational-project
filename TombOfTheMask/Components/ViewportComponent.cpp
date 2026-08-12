#include "ViewportComponent.h"
#include "GUI/LevelHUD.h"

void UViewportComponent::AddPoint()
{
    ++PointCount;
    LevelHUD->UpdateHUDState(StarCount, PointCount);
}

UViewportComponent::UViewportComponent(AActor* componentOwner) : UActorComponent(componentOwner)
{
    LevelHUD = Construct<ULevelHUD>(nullptr);
}

void UViewportComponent::AddStar()
{
    ++StarCount;
    LevelHUD->UpdateHUDState(StarCount, PointCount);
}