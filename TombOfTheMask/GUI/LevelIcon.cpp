#include "LevelIcon.h"
#include "Core/DataFunctions.h"
#include "Base/TextBlock.h"
#include "Base/Image.h"

ULevelIcon::ULevelIcon(UUserWidget* parent) : UUserWidget(parent)
{
    LevelImage = std::make_unique<UImage>(this);
    LevelImage->SetTextureByName("level_icon");

    PointCountText = std::make_unique<UTextBlock>(this);
    StarCountText = std::make_unique<UTextBlock>(this);
}

void ULevelIcon::SetLevelInfo(int levelIndex)
{
    std::string key = "Level" + std::to_string(levelIndex);

    // Переменные для вывода текста
    int value, maxValue;
    std::string text;

    value = GetDataParameter(key + ".stars:");
    maxValue = GetDataParameter(key + ".maxstars:");
    text = std::to_string(value) + " / " + std::to_string(maxValue);
    StarCountText->SetText(text);

    value = GetDataParameter(key + ".points:");
    maxValue = GetDataParameter(key + ".maxpoints:");
    text = std::to_string(value) + " / " + std::to_string(maxValue);
    PointCountText->SetText(text);

    UpdateLevelIcon(levelIndex);
}

void ULevelIcon::UpdateLevelIcon(int levelIndex)
{
    std::string levelIcon;
    int LastLevel = levelIndex - 1;

    if (LastLevel == 0)
        levelIcon = GetDataParameter("Level1:") ? "completed_level_icon" : "level_icon";

    if (GetDataParameter("Level" + std::to_string(LastLevel) + ":") == 0)
        levelIcon = "locked_level_icon";
    else
        levelIcon =
            GetDataParameter("Level" + std::to_string(levelIndex) + ":") ? "completed_level_icon" : "level_icon";

    LevelImage->SetTextureByName(levelIcon);
}