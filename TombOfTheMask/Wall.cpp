#include "Wall.h"

Wall::Wall(sf::Vector2f position) : Actor(ActorType::Wall, position)
{
}

void Wall::Update()
{
}

void Wall::OnCollision(Actor* OtherActor)
{
}
