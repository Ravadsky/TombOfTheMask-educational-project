#pragma once
#include "GameState.h"

class Button;
class SpriteComponent;

class LevelEditorSelector : public GameState
{
  private:
    std::unique_ptr<SpriteComponent> Background;
    sf::Texture BackgroundTexture;

    std::unique_ptr<Button> Level1;
    std::unique_ptr<Button> Level2;
    std::unique_ptr<Button> Level3;

  public:
    LevelEditorSelector();
    virtual void Update() override;

    void ChooseLevel(int index);
};
