#include "LevelSubsystem.h"
#include "Actor.h"

LevelSubsystem::LevelSubsystem()
{

}

void LevelSubsystem::BeginPlay()
{
	Actor* Player = new Actor();

	for (auto _actor : ActorsOnLevel)
	{
		_actor->BeginPlay();
	}
}
void LevelSubsystem::Update()
{
	for (auto _actor : ActorsOnLevel)
	{
		_actor->Update();
	}
}
