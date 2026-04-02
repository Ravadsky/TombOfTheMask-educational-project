#include "Point.h"
#include "LevelSubsystem.h"
#include "Player.h"
#include "FunctionLibrary.h"

Point::Point(sf::Vector2f position, float rotationAngle) : Actor(ActorType::Point, position, rotationAngle)
{
	Collision = CollisionPreset::Overlap;

}

void Point::Update()
{
}

void Point::OnCollision(std::weak_ptr<Actor> OtherActor)
{

	if (auto other = OtherActor.lock())
	{
		if (other.get() != this)
		{
			if (isClassOf<Player>(other))
			{
				GLevelSubsystem->CurrentPlayer.lock().get()->AddPoint();
				MarkToKill();
			}
		}
	}

}
