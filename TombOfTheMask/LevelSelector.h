#pragma once
#include "GameState.h"

class Button;
class SpriteComponent;

class LevelSelector : public GameState
{
  private:
    std::unique_ptr<Button> Level1;
    std::unique_ptr<SpriteComponent> Level1Sprite;

    std::unique_ptr<Button> Level2;
    std::unique_ptr<SpriteComponent> Level2Sprite;

    std::unique_ptr<Button> Level3;
    std::unique_ptr<SpriteComponent> Level3Sprite;

    sf::Texture LevelTexture;
    sf::Texture CompletedLevelTexture;
    sf::Texture LockedLevelTexture;

  public:
    LevelSelector();
    void Update() override;

    void ChooseLevel(int index);
};
