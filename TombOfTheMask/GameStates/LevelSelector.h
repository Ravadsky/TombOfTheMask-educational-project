#pragma once
#include "GameState.h"

class Button;
class LevelInfo;
class SpriteComponent;

class LevelSelector : public GameState
{
  private:
    std::unique_ptr<SpriteComponent> Background;
    sf::Texture BackgroundTexture;

    std::unique_ptr<Button> Level1;
    std::unique_ptr<LevelInfo> Level1Sprite;

    std::unique_ptr<Button> Level2;
    std::unique_ptr<LevelInfo> Level2Sprite;

    std::unique_ptr<Button> Level3;
    std::unique_ptr<LevelInfo> Level3Sprite;

    sf::Texture LevelTexture;
    sf::Texture CompletedLevelTexture;
    sf::Texture LockedLevelTexture;

  public:
    LevelSelector();
    virtual void Update() override;

    void ChooseLevel(int index);

    sf::Texture *getLevelSprite(int CurrentLevel);
};
