#pragma once
#include "Base/UserWidget.h"

class UTextBlock;
class UImage;

class ULevelHUD : public UUserWidget
{
public:
    ULevelHUD(UUserWidget* parent);

    virtual void BeginPlay() override;

    void UpdateHUDState(int newStarCount, int newPointCount);

protected:
    std::unique_ptr<UImage> StarImage;
    std::unique_ptr<UTextBlock> StarText;

    std::unique_ptr<UImage> PointImage;
    std::unique_ptr<UTextBlock> PointText;
};
