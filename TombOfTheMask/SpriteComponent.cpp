#include "SpriteComponent.h"
#include "ResourceSubSystem.h"

SpriteComponent::SpriteComponent(int&& index) : Drawable()
{
	ObjectSprite.setTexture(GResourceSubsystem->SpriteSheet);
	ObjectSprite.setTextureRect({ index * RAW_SPRITE_SIZE, 0, RAW_SPRITE_SIZE, RAW_SPRITE_SIZE });
	ObjectSprite.setOrigin({ RAW_SPRITE_SIZE / 2, RAW_SPRITE_SIZE / 2 });
	ObjectSprite.setScale(OBJECT_SIZE);
	ObjectSprite.setPosition(CAMERA_PIVOT);
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

void SpriteComponent::SetPosition(sf::Vector2f Position)
{
	ObjectSprite.setPosition(Position);
}
