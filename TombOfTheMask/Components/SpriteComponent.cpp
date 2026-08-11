#include "SpriteComponent.h"
#include "Core/GameSubsystems/RenderSubsystem.h"
#include "Core/GameSubsystems/ResourceSubsystem.h"

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

    GetRenderSubsystem()->ActorsToDraw.push_back(this);

    // anim part
    // int indexRow = index % SpriteSheetSize;
    // int indexColumn = index / SpriteSheetSize;
    // ObjectSprite.setTextureRect(
    //   { indexRow * RAW_SPRITE_SIZE, indexColumn * RAW_SPRITE_SIZE, RAW_SPRITE_SIZE, RAW_SPRITE_SIZE });
}

USpriteComponent::~USpriteComponent()
{
    RemoveFromVectorByRef(GetRenderSubsystem()->ActorsToDraw, this);
}

void USpriteComponent::Render(sf::Vector2f cameraOrigin)
{
    if (sprite.getTexture() != nullptr)
    {
        sprite.setPosition(CAMERA_PIVOT - cameraOrigin + GetWorldLocation());
        Window->draw(sprite);
    }
}

void USpriteComponent::SetSpriteTexture(const std::string& textureName)
{
    auto& texture = GetResourceSubsystem()->GetTexture(textureName);
    sprite.setTexture(texture);
}
