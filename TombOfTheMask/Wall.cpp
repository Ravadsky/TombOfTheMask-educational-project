#include "Wall.h"

Wall::Wall(sf::Vector2f position, float rotationAngle) : Actor(ActorType::Wall, position, rotationAngle)
{
	Collision = CollisionPreset::Block;

}

void Wall::Update()
{
}

void Wall::OnCollision(std::weak_ptr<Actor> OtherActor)
{
}
