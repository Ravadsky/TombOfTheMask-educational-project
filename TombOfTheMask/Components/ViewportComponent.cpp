#include "ViewportComponent.h"
#include "GUI/LevelHUD.h"

#include "Actors/Actor.h"
#include "World/World.h"
#include "Core/DataFunctions.h"

void UViewportComponent::AddPoint()
{
    ++PointCount;

    LevelHUD->UpdateHUDState(StarCount, maxStars, PointCount, maxPoints);
}

UViewportComponent::UViewportComponent(AActor* componentOwner) : UActorComponent(componentOwner)
{
    LevelHUD = Construct<ULevelHUD>(nullptr);

    std::string key = "Level" + std::to_string(GetDataParameter("CurrentLevel:"));
    maxStars = GetDataParameter(key + ".maxstars:");
    maxPoints = GetDataParameter(key + ".maxpoints:");

    LevelHUD->UpdateHUDState(0, maxStars, 0, maxPoints);
}

void UViewportComponent::AddStar()
{
    ++StarCount;

    LevelHUD->UpdateHUDState(StarCount, maxStars, PointCount, maxPoints);
}