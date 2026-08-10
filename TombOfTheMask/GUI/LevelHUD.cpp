#include "LevelHUD.h"
#include "TextBlock.h"
#include "Core/GameSubsystems/AudioSubsystem.h"

ULevelHUD::ULevelHUD()
{
    StarText = std::unique_ptr<UTextBlock>();
    PointText = std::unique_ptr<UTextBlock>();
}

void ULevelHUD::BeginPlay()
{
    UpdateHUDState(0, 0);
}

void ULevelHUD::UpdateHUDState(int newStarCount, int newPointCount)
{
    std::string PointText = std::to_string(newPointCount) + " / " + std::to_string(3);

    std::string StarText = std::to_string(newStarCount) + " / " + std::to_string(3);

    GetAudioSubsystem()->PlaySound("point_sound");
}
