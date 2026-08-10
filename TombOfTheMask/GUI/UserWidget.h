#pragma once
#include "Core/UObject.h"

class UUserWidget : public UObject
{
protected:

    sf::Vector2f screenPosition = { 0.0f, 0.0f };

public:
    UUserWidget();
    virtual ~UUserWidget();

    inline void SetScreenPosition(sf::Vector2f newPosition) { screenPosition = newPosition; };

    virtual void Render() {};
};
