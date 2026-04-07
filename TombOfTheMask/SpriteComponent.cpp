#include "SpriteComponent.h"
#include "ResourceSubSystem.h"

SpriteComponent::SpriteComponent(int &&index, sf::Vector2f position) : Drawable()
{
    ObjectSprite.setTexture(GResourceSubsystem->SpriteSheet);
    ObjectSprite.setOrigin({RAW_SPRITE_SIZE / 2, RAW_SPRITE_SIZE / 2});
    ObjectSprite.setScale(PIXEL_RATIO);
    WorldPosition = position;

    int indexRow = index % SpriteSheetSize;
    int indexColumn = index / SpriteSheetSize;
    ObjectSprite.setTextureRect(
        {indexRow * RAW_SPRITE_SIZE, indexColumn * RAW_SPRITE_SIZE, RAW_SPRITE_SIZE, RAW_SPRITE_SIZE});
}

SpriteComponent::SpriteComponent(sf::Texture &texture, sf::Vector2f position)
{
    ObjectSprite.setTexture(texture);
    ObjectSprite.setScale(PIXEL_RATIO);
    WorldPosition = position;

    sf::FloatRect bounds = ObjectSprite.getLocalBounds();
    ObjectSprite.setOrigin(std::floor(bounds.left + bounds.width / 2.0f),
                           std::floor(bounds.top + bounds.height / 2.0f));
}

void SpriteComponent::BeginPlay()
{
}

void SpriteComponent::Update()
{
}

void SpriteComponent::Draw(sf::Vector2f position)
{
    ObjectSprite.setPosition(WorldPosition - position);
    GWindow->draw(ObjectSprite);
}

void SpriteComponent::SetPosition(sf::Vector2f position)
{
    WorldPosition = position;
}

void SpriteComponent::SetColor(sf::Color color)
{
    ObjectSprite.setColor(color);
}

void SpriteComponent::SetRotation(float Angle)
{
    ObjectSprite.setRotation(Angle);
}

void SpriteComponent::Flip(bool flip)
{
    if (flip)
        ObjectSprite.setScale(-PIXEL_RATIO.x, PIXEL_RATIO.y);
    else
        ObjectSprite.setScale(PIXEL_RATIO.x, PIXEL_RATIO.y);
}

void SpriteComponent::SetDrawType(DrawType type)
{
    Type = type;
}

sf::FloatRect SpriteComponent::GetBounds()
{
    return ObjectSprite.getGlobalBounds();
}
