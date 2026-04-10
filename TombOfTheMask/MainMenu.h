#pragma once
#include "Button.h"
#include "GameState.h"

class MainMenu : public GameState
{
  private:
    std::unique_ptr<Button> StartGameButton;
    std::unique_ptr<Button> EditorButton;
    std::unique_ptr<Button> ExitButton;

  public:
    MainMenu();
    void Update() override;
};
