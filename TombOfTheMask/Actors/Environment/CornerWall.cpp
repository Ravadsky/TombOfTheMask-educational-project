#include "CornerWall.h"

CornerWall::CornerWall(sf::Vector2f position, float rotationAngle)
    : Actor(ActorType::CornerWall, position, rotationAngle)
{
    Collision = CollisionPreset::Block;
}