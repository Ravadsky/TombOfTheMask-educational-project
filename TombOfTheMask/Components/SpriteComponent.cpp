#include "SpriteComponent.h"

void USpriteComponent::SetColor(sf::Color color)
{
    sprite.setColor(color);
}

void USpriteComponent::Flip(bool flip)
{
    if (flip)
        sprite.setScale(-PIXEL_RATIO.x, PIXEL_RATIO.y);
    else
        sprite.setScale(PIXEL_RATIO.x, PIXEL_RATIO.y);
}

sf::FloatRect USpriteComponent::GetBounds()
{
    return sprite.getGlobalBounds();
}

USpriteComponent::USpriteComponent(AActor* componentOwner) : USceneComponent(componentOwner)
{
    sprite.setOrigin({ RAW_SPRITE_SIZE / 2, RAW_SPRITE_SIZE / 2 });
    sprite.setScale(PIXEL_RATIO);

    // anim part
    // int indexRow = index % SpriteSheetSize;
    // int indexColumn = index / SpriteSheetSize;
    // ObjectSprite.setTextureRect(
    //   { indexRow * RAW_SPRITE_SIZE, indexColumn * RAW_SPRITE_SIZE, RAW_SPRITE_SIZE, RAW_SPRITE_SIZE });
}

void USpriteComponent::Render()
{
    if (sprite.getTexture() != nullptr)
    {
        sprite.setPosition(GetCameraLocation() - location);
        Window->draw(sprite);
    }
}

void USpriteComponent::SetSpriteTexture(const sf::Texture& newTexture)
{
    sprite.setTexture(newTexture);
}
