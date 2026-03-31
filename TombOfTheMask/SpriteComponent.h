#pragma once
#include "UObject.h"
#include "Drawable.h"

class SpriteComponent :
    public UObject,
    public Drawable
{
private:
    sf::Sprite ObjectSprite;

public:
    SpriteComponent(int&& index);
    void BeginPlay() override;
    void Update() override;
    void Draw() override;

    void SetPosition(sf::Vector2f Position);
};

