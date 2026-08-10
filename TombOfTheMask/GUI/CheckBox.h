#pragma once
#include "UserWidget.h"

class SpriteComponent;

class UCheckBox : public UUserWidget
{
private:
    sf::Texture TextureOn, TextureOff;
    sf::Sprite Sprite;

    bool CurrentState;

public:
    UCheckBox(std::string SpriteOn, std::string SpriteOff);

    void TriggerIfCollision(int xMousePos, int yMousePos);

    void SetInitState(bool State);
    bool ChangeState();

    virtual void Render() override;

    FDelegate<> onCheckBoxPressed;
};
