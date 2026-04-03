#include "PlayerStartBlock.h"

PlayerStartBlock::PlayerStartBlock(sf::Vector2f position, float rotationAngle) : Actor(ActorType::PlayerStartBlock, position, rotationAngle)
{
	Collision = CollisionPreset::Block;

}

void PlayerStartBlock::Update()
{
}

void PlayerStartBlock::OnCollision(std::weak_ptr<Actor> OtherActor)
{
}
