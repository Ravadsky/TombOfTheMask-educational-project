#pragma once
#include "UObject.h"

#include "SpriteComponent.h"
#include "TextBox.h"

class Widget : public UObject
{
  private:
    std::unique_ptr<SpriteComponent> WidgetSprite;
    std::unique_ptr<TextBox> WidgetText;

    sf::Texture WidgetTexture;

public:
    Widget(sf::Vector2f position, std::string fileName, std::string widgetText);

    void UpdateState(std::string newString);
};
