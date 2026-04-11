#pragma once
#include "UObject.h"

#include "SpriteComponent.h"
#include "TextBox.h"

class Button : public UObject
{
  private:
    std::unique_ptr<SpriteComponent> ButtonSprite;
    std::unique_ptr<TextBox> ButtonText;
    sf::Texture ButtonTexture;

  public:
    Button(std::string fileName, sf::Vector2f pos);

    bool CheckWithCollisions(int xMousePos, int yMousePos);
};
