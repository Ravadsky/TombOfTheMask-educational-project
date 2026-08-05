#pragma once
#include "Drawable.h"
#include "UObject.h"

class SpriteComponent : public UObject, public Drawable
{
  protected:
    sf::Sprite ObjectSprite;
    sf::Vector2f WorldPosition{0.f, 0.f};

  public:
    SpriteComponent(int &&index, sf::Vector2f position);
    SpriteComponent(sf::Texture &texture, sf::Vector2f position);

    virtual void Draw(sf::Vector2f position = {0.f, 0.f}) override;

    void SetPosition(sf::Vector2f position);
    void SetColor(sf::Color color);
    void SetRotation(float Angle);
    void Flip(bool flip);
    void SetNewTexture(sf::Texture &texture);

    void SetDrawType(DrawType type);

    sf::FloatRect GetBounds();

};
