#include "Spikes.h"
#include "LevelSubsystem.h"

Spikes::Spikes(sf::Vector2f position, float rotationAngle) : Actor(ActorType::Spikes, position, rotationAngle)
{
	Collision = CollisionPreset::Block;
}

void Spikes::Update()
{
}

void Spikes::OnCollision(std::weak_ptr<Actor> OtherActor)
{
	GLevelSubsystem->RestartLevel();
}
