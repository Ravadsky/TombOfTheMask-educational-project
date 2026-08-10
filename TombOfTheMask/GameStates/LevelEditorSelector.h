#pragma once
#include "GameState.h"

class UButton;

class ULevelEditorSelector : public UGameState
{
private:
    std::unique_ptr<UButton> Level1Button;
    void OnLevel1ButtonPressed();

    std::unique_ptr<UButton> Level2Button;
    void OnLevel2ButtonPressed();

    std::unique_ptr<UButton> Level3Button;
    void OnLevel3ButtonPressed();


public:
    ULevelEditorSelector();
    virtual void Update(float deltaTime) override;

    void ChooseLevel(int index);
};
