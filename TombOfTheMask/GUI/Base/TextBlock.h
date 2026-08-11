#pragma once
#include "UserWidget.h"

class UTextBlock : public UUserWidget
{
protected:
    sf::Text TextContainer;

public:
    UTextBlock(UUserWidget* parent);

    virtual void Render() override;

    void SetText(std::string newString);
};
