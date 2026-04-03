#include "PhysicsSubsystem.h"
#include "LevelSubsystem.h"
#include "Player.h"
#include "FunctionLibrary.h"

PhysicsSubsystem::PhysicsSubsystem()
{
}

void PhysicsSubsystem::BeginPlay()
{
	for (auto actor : GLevelSubsystem->ActorsOnLevel)
	{
		if (actor->CanTriggerCollision()) TriggerActors.emplace_back(actor);
	}
}

void PhysicsSubsystem::Update()
{
	DeltaTimer = GameClock.restart();
	DeltaTime = DeltaTimer.asSeconds();

	ClearVectorForExpiredPtr(TriggerActors);

	for (auto actor : GLevelSubsystem->ActorsOnLevel)
	{
		for (auto otherActor : TriggerActors)
		{
			if (auto _otherActor = otherActor.lock())
			{
				if (actor->GetCollisionBox().intersects(_otherActor->GetCollisionBox()))
				{
					_otherActor->OnCollision(actor);
					actor->OnCollision(_otherActor);
				}
			}

		}
	}
}

float PhysicsSubsystem::GetElapsedTime()
{
	return DeltaTime;
}


