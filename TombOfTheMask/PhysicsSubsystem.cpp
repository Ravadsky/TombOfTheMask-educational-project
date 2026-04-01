#include "PhysicsSubsystem.h"
#include "LevelSubsystem.h"
#include "Player.h"

PhysicsSubsystem::PhysicsSubsystem()
{
}

void PhysicsSubsystem::BeginPlay()
{
}

void PhysicsSubsystem::Update()
{
	auto _player = GLevelSubsystem->CurrentPlayer;

	for (auto _actor : GLevelSubsystem->ActorsOnLevel)
	{
		if (dynamic_cast<Player*>(_actor)) continue;

		if (_player->GetCollisionBox().intersects(_actor->GetCollisionBox()))
		{
			_player->OnCollision(_actor);
		}

	}
}


