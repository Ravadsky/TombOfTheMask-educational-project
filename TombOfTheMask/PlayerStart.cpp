#include "PlayerStart.h"

PlayerStart::PlayerStart(sf::Vector2f position, float rotationAngle)
    : Actor(ActorType::PlayerStart, position, rotationAngle)
{
    Collision = CollisionPreset::Ignore;
}

void PlayerStart::Update()
{
}

void PlayerStart::OnCollision(std::weak_ptr<Actor> OtherActor)
{
}
