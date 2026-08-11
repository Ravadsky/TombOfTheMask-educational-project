#pragma once
#include "Base/UserWidget.h"

class UTextBlock;
class UImage;

class UButton : public UUserWidget
{
protected:
    std::unique_ptr<UImage> ButtonImage;
    std::unique_ptr<UTextBlock> ButtonText;

public:
    UButton(UUserWidget* parent);

    void TriggerIfCollision(int xMousePos, int yMousePos);
    void SetButtonText(std::string newText);

    virtual void Render() override;

    FDelegate<> onButtonPressed;
};

