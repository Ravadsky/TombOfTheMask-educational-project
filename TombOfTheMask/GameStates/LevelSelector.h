#pragma once
#include "GameState.h"

class UButton;
class ULevelIcon;
class UImage;

class ULevelSelector : public UGameState
{
private:
    std::unique_ptr<UImage> CanvasImage;

    std::unique_ptr<UButton> Level1Button;
    std::unique_ptr<ULevelIcon> Level1Icon;
    void OnLevel1ButtonPressed();

    std::unique_ptr<UButton> Level2Button;
    std::unique_ptr<ULevelIcon> Level2Icon;
    void OnLevel2ButtonPressed();

    std::unique_ptr<UButton> Level3Button;
    std::unique_ptr<ULevelIcon> Level3Icon;
    void OnLevel3ButtonPressed();

public:
    ULevelSelector();
    void ChooseLevel(int index);
};
