#pragma once
#include "Drawable.h"
#include "UObject.h"

class TextBox : public UObject, public Drawable
{
  private:
    sf::Text TextContainer;
    sf::Vector2f TextPosition;

  public:
    TextBox(std::string text, sf::Vector2f pos);

    void BeginPlay() override;
    void Update() override;
    void Draw(sf::Vector2f position = {0.f, 0.f}) override;

    void ChangeText(std::string newString);
};
