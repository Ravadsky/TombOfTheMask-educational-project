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

    SpriteComponent(int&& index, sf::Vector2f position);

    void BeginPlay() override;
    void Update() override;
    void Draw() override;

    void SetPosition(sf::Vector2f position);

    void SetRotation(float Angle);
    void Flip(bool flip);

    void SetDrawType(DrawType type);
};

