#pragma once
#include "UObject.h"

class SpriteComponent;
class TextBox;

class LevelInfo : public UObject
{
  private:
    std::unique_ptr<SpriteComponent> LevelSprite;
    std::unique_ptr<TextBox> PointCountText;
    std::unique_ptr<TextBox> StarCountText;

  public:
    LevelInfo(sf::Vector2f pos, sf::Texture &tex, int levelIndex);
};
