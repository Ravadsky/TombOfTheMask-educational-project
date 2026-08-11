#pragma once
#include "Button.h"

class UCheckBox : public UButton
{
protected:
    std::string TextureOn, TextureOff;
    bool CurrentState;

public:
    UCheckBox(UUserWidget* parent);

    void SetInitState(bool State);
    bool ChangeState();
    void SetTextureNames(std::string textureOn, std::string textureOff);
};
