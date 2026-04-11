#include "Wall.h"

Wall::Wall(sf::Vector2f position, float rotationAngle) : Actor(ActorType::Wall, position, rotationAngle)
{
    Collision = CollisionPreset::Block;
}