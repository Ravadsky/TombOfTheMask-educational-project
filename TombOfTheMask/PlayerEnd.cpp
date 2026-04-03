#include "PlayerEnd.h"

PlayerEnd::PlayerEnd(sf::Vector2f position, float rotationAngle) : Actor(ActorType::PlayerEnd, position, rotationAngle)
{
	Collision = CollisionPreset::Block;

}

void PlayerEnd::Update()
{
}

void PlayerEnd::OnCollision(std::weak_ptr<Actor> OtherActor)
{
}
