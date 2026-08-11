#pragma once
#include "Base/UserWidget.h"

class UTextBlock;
class UImage;

class ULevelIcon : public UUserWidget
{
private:
    std::unique_ptr<UImage> LevelImage;
    std::unique_ptr<UTextBlock> PointCountText;
    std::unique_ptr<UTextBlock> StarCountText;

public:
    ULevelIcon(UUserWidget* parent);

    void SetLevelInfo(int levelIndex);
    void UpdateLevelIcon(int levelIndex);
};
