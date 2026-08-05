#include "PlayerStartBlock.h"

PlayerStartBlock::PlayerStartBlock(sf::Vector2f position, float rotationAngle)
    : Actor(ActorType::PlayerStartBlock, position, rotationAngle)
{
    Collision = CollisionPreset::Block;
}