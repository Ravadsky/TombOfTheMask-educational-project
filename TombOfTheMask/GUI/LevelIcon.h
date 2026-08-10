#pragma once
#include "UserWidget.h"

class UTextBlock;

class ULevelIcon : public UUserWidget
{
  private:
    sf::Sprite Sprite;
    std::unique_ptr<UTextBlock> PointCountText;
    std::unique_ptr<UTextBlock> StarCountText;

  public:
    virtual void Render() override;


    //LevelInfo(sf::Vector2f pos, sf::Texture &tex, int levelIndex);
};
