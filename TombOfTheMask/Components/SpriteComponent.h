#pragma once
#include "SceneComponent.h"

enum class ERenderLayer : int
{
    back = 0,
    medium = 1,
    forward = 2,
};

class USpriteComponent : public USceneComponent
{
protected:
    sf::Sprite sprite;
    ERenderLayer renderLayer = ERenderLayer::medium;

public:
    USpriteComponent(AActor* componentOwner);
    virtual ~USpriteComponent();

    void Render();

    void SetSpriteTexture(const std::string& textureName);

    void SetColor(sf::Color color);
    void Flip(bool flip);

    sf::FloatRect GetBounds();
};
