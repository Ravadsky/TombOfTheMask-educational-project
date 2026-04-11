#pragma once
#include "GameState.h"

class Button;
class SpriteComponent;
class CheckBox;

class MainMenu : public GameState
{
  private:
    std::unique_ptr<SpriteComponent> Background;
    sf::Texture BackgroundTexture;

    std::unique_ptr<Button> StartGameButton;
    std::unique_ptr<Button> EditorButton;
    std::unique_ptr<Button> ExitButton;

    std::unique_ptr<CheckBox> SoundBox;
    std::unique_ptr<CheckBox> MusicBox;

  public:
    MainMenu();

    virtual void Update() override;
};
