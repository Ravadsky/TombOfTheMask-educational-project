#include "SpriteComponent.h"
#include "ResourceSubSystem.h"

SpriteComponent::SpriteComponent(int&& index, sf::Vector2f position) : Drawable()
{
	ObjectSprite.setTexture(GResourceSubsystem->SpriteSheet);
	ObjectSprite.setOrigin({ RAW_SPRITE_SIZE / 2, RAW_SPRITE_SIZE / 2 });
	ObjectSprite.setScale(PIXEL_RATIO);
	ObjectSprite.setPosition(position);

	int indexRow = index % SpriteSheetSize;
	int indexColumn = index / SpriteSheetSize;
	ObjectSprite.setTextureRect({ indexRow * RAW_SPRITE_SIZE, indexColumn * RAW_SPRITE_SIZE, RAW_SPRITE_SIZE, RAW_SPRITE_SIZE });

}

void SpriteComponent::BeginPlay()
{
}

void SpriteComponent::Update()
{
}

void SpriteComponent::Draw()
{
	GWindow->draw(ObjectSprite);
}

void SpriteComponent::SetPosition(sf::Vector2f position)
{
	ObjectSprite.setPosition(position);
}

void SpriteComponent::SetRotation(float Angle)
{
	ObjectSprite.setRotation(Angle);
}

void SpriteComponent::Flip(bool flip)
{
	if (flip)	ObjectSprite.setScale(-PIXEL_RATIO.x , PIXEL_RATIO.y);
	else ObjectSprite.setScale(PIXEL_RATIO.x, PIXEL_RATIO.y);

}

void SpriteComponent::SetDrawType(DrawType type)
{
	Type = type;
}
