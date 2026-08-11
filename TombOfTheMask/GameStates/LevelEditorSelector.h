#pragma once
#include "GameState.h"

class UButton;
class UImage;

class ULevelEditorSelector : public UGameState
{
private:
    std::unique_ptr<UImage> CanvasImage;

    std::unique_ptr<UButton> Level1Button;
    void OnLevel1ButtonPressed();

    std::unique_ptr<UButton> Level2Button;
    void OnLevel2ButtonPressed();

    std::unique_ptr<UButton> Level3Button;
    void OnLevel3ButtonPressed();

public:
    ULevelEditorSelector();

    void ChooseLevel(int index);
};
