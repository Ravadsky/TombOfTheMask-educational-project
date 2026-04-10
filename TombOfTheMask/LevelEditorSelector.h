#pragma once
#include "GameState.h"

class Button;

class LevelEditorSelector : public GameState
{
  private:
    std::unique_ptr<Button> Level1;
    std::unique_ptr<Button> Level2;
    std::unique_ptr<Button> Level3;

  public:
    LevelEditorSelector();
    void Update() override;

    void ChooseLevel(int index);
};
