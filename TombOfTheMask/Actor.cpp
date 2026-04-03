#include "Actor.h"
#include "LevelSubsystem.h"
#include "FunctionLibrary.h"

Actor::Actor(ActorType Type, sf::Vector2f position, float rotationAngle)
{
	ActorLocation = position;
	CollisionBox = { position.x - SPRITE_GAME_SIZE / 2, position.y - SPRITE_GAME_SIZE / 2, SPRITE_GAME_SIZE, SPRITE_GAME_SIZE };

	ActorSprite = std::make_unique<SpriteComponent>(static_cast<int>(Type), position);

	ActorRotation = rotationAngle;
	ActorSprite->SetRotation(rotationAngle);
}

void Actor::BeginPlay()
{
}

bool Actor::CanTick()
{
	return canTick;
}

bool Actor::CanTriggerCollision()
{
	return triggerCollision;
}

sf::Vector2f Actor::Getlocation()
{
	return ActorLocation;
}

sf::FloatRect Actor::GetCollisionBox()
{
	return CollisionBox;
}

CollisionPreset Actor::GetCollisionPreset()
{
	return Collision;
}

void Actor::MarkToKill()
{
	GGarbageCollector->ActorsToKill.push_back(shared_from_this());
}

