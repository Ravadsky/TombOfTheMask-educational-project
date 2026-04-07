#pragma once
#include "SpriteComponent.h"
#include "UObject.h"
#include "TextBox.h"

class Button : public UObject
{
  private:
    std::unique_ptr<SpriteComponent> ButtonSprite;
    std::unique_ptr<TextBox> ButtonText;
    sf::Texture ButtonTexture;

  public:
    Button(std::string fileName, sf::Vector2f pos);

    void BeginPlay() override;
    void Update() override;

    bool CheckWithCollisions(int xMousePos, int yMousePos);
};
