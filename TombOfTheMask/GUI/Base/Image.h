#pragma once
#include "UserWidget.h"

class UImage : public UUserWidget
{
protected:
    sf::Sprite Sprite;

public:
    UImage(UUserWidget* parent);

    virtual void Render() override;

    void SetTextureByName(std::string newString);
    bool ContainsMouse(sf::Vector2f mouseCoords);
};
