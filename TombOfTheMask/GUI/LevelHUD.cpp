#include "LevelHUD.h"
#include "Core/GameSubsystems/AudioSubsystem.h"
#include "Base/TextBlock.h"
#include "Base/Image.h"

ULevelHUD::ULevelHUD(UUserWidget* parent) : UUserWidget(parent)
{
    StarText = std::make_unique<UTextBlock>(this);
    StarImage = std::make_unique<UImage>(this);
    StarImage->SetTextureByName("star");

    PointText = std::make_unique<UTextBlock>(this);
    PointImage = std::make_unique<UImage>(this);
    PointImage->SetTextureByName("point");
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
