#include "Spikes.h"
#include "LevelSubsystem.h"
#include "FunctionLibrary.h"
#include "Player.h"

Spikes::Spikes(sf::Vector2f position, float rotationAngle) : Actor(ActorType::Spikes, position, rotationAngle)
{
	Collision = CollisionPreset::Block;
}

void Spikes::Update()
{
}

void Spikes::OnCollision(std::weak_ptr<Actor> OtherActor)
{
	if (auto other = OtherActor.lock())
	{
		if (other.get() != this)
		{
			switch (other->GetCollisionPreset())
			{
			case CollisionPreset::Block:
				if (isClassOf<Player>(other)) CastTo<Player>(other)->GetDamage();
				break;
			case CollisionPreset::Overlap:

				break;
			case CollisionPreset::Ignore:

				break;
			}
		}
	}

}
