#include "Actor.h"
#include "LevelSubsystem.h"

Actor::Actor(ActorType Type, sf::Vector2f position)
{
	GLevelSubsystem->ActorsOnLevel.push_back(this);

	ActorLocation = position;
	CollisionBox = { position.x - SPRITE_GAME_SIZE / 2, position.y - SPRITE_GAME_SIZE / 2, SPRITE_GAME_SIZE, SPRITE_GAME_SIZE };

	ActorSprite = new SpriteComponent(static_cast<int>(Type), position);
}

Actor::~Actor()
{
	auto ItemIterator = std::find(GLevelSubsystem->ActorsOnLevel.begin(), GLevelSubsystem->ActorsOnLevel.end(), this);
	GLevelSubsystem->ActorsOnLevel.erase(ItemIterator);
}

void Actor::BeginPlay()
{
}

bool Actor::CanTick()
{
	return canTick;
}

sf::Vector2f Actor::Getlocation()
{
	return ActorLocation;
}

sf::FloatRect Actor::GetCollisionBox()
{
	return CollisionBox;
}
