#include "PlayerEndBlock.h"

PlayerEndBlock::PlayerEndBlock(sf::Vector2f position, float rotationAngle) : Actor(ActorType::PlayerEndBlock, position, rotationAngle)
{
	Collision = CollisionPreset::Block;

}

void PlayerEndBlock::Update()
{
}

void PlayerEndBlock::OnCollision(std::weak_ptr<Actor> OtherActor)
{
}
