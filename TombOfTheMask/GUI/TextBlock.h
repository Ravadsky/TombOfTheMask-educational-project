#pragma once
#include "UserWidget.h"

class UTextBlock : public UUserWidget
{
  private:
    sf::Text TextContainer;

  public:
    UTextBlock();

    virtual void Render() override;

    void SetText(std::string newString);
};
