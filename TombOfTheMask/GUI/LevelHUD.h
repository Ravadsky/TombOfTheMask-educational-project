#pragma once
#include "UserWidget.h"

class UTextBlock;

class ULevelHUD : public UUserWidget
{
public:
    ULevelHUD();

    virtual void BeginPlay() override;

    void UpdateHUDState(int newStarCount, int newPointCount);

private:
    sf::Sprite StarSprite;
    std::unique_ptr<UTextBlock> StarText;

    sf::Sprite PointSprite;
    std::unique_ptr<UTextBlock> PointText;
};
