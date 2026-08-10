#pragma once
#include "UserWidget.h"
#include "TextBlock.h"

class UButton : public UUserWidget
{
private:
    sf::Sprite Sprite;
    std::unique_ptr<UTextBlock> ButtonText;

    sf::Texture ButtonTexture;

public:
    UButton(std::string fileName);

    void TriggerIfCollision(int xMousePos, int yMousePos);

    virtual void Render() override;

    FDelegate<> onButtonPressed;
};
