#include "LevelHUD.h"
#include "Core/GameSubsystems/AudioSubsystem.h"
#include "Base/TextBlock.h"
#include "Base/Image.h"

ULevelHUD::ULevelHUD(UUserWidget* parent) : UUserWidget(parent)
{
    StarText = std::make_unique<UTextBlock>(this);
    StarText->SetAlignment(EHorizontalAlignment::Right, EVerticalAlignment::Top);
    StarText->SetScreenPosition({ -120.0f, 120.0f });

    StarImage = std::make_unique<UImage>(this);
    StarImage->SetTextureByName("star");
    StarImage->SetAlignment(EHorizontalAlignment::Right, EVerticalAlignment::Top);
    StarImage->SetScreenPosition({ -224.0f, 120.0f });

    PointText = std::make_unique<UTextBlock>(this);
    PointText->SetAlignment(EHorizontalAlignment::Right, EVerticalAlignment::Top);
    PointText->SetScreenPosition({ -120.0f, 240.0f });

    PointImage = std::make_unique<UImage>(this);
    PointImage->SetTextureByName("point");
    PointImage->SetAlignment(EHorizontalAlignment::Right, EVerticalAlignment::Top);
    PointImage->SetScreenPosition({ -224.0f, 240.0f });
}

void ULevelHUD::BeginPlay()
{
    UpdateHUDState(0, 0);
}

void ULevelHUD::UpdateHUDState(int newStarCount, int newPointCount)
{
    std::string pointString = std::to_string(newPointCount) + " / " + std::to_string(3);
    PointText->SetText(pointString);

    std::string starString = std::to_string(newStarCount) + " / " + std::to_string(3);
    StarText->SetText(starString);

    GetAudioSubsystem()->PlaySound("point");
}
