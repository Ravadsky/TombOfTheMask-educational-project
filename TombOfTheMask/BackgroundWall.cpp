#include "BackgroundWall.h"

BackgroundWall::BackgroundWall(sf::Vector2f position, float rotationAngle) : Actor(ActorType::BackgroundWall, position, rotationAngle)
{
	Collision = CollisionPreset::Ignore;
}

void BackgroundWall::Update()
{
}

void BackgroundWall::OnCollision(std::weak_ptr<Actor> OtherActor)
{
}
