#include "LevelSubsystem.h"
#include "Player.h"
#include "Wall.h"
#include "FunctionLibrary.h"

LevelSubsystem::LevelSubsystem()
{

}

void LevelSubsystem::BeginPlay()
{
	CurrentPlayer = SpawnActor<Player>({ 3.f, 3.f });

	SpawnActor<Wall>({ 1.f,1.f });
	SpawnActor<Wall>({ 1.f,2.f });
	SpawnActor<Wall>({ 1.f,3.f });
	SpawnActor<Wall>({ 1.f,4.f });
	SpawnActor<Wall>({ 1.f,5.f });

	SpawnActor<Wall>({ 5.f,1.f });
	SpawnActor<Wall>({ 5.f,2.f });
	SpawnActor<Wall>({ 5.f,3.f });
	SpawnActor<Wall>({ 5.f,4.f });
	SpawnActor<Wall>({ 5.f,5.f });

	SpawnActor<Wall>({ 2.f,1.f });
	SpawnActor<Wall>({ 3.f,1.f });
	SpawnActor<Wall>({ 4.f,1.f });

	SpawnActor<Wall>({ 2.f,5.f });
	SpawnActor<Wall>({ 4.f,5.f });

	SpawnActor<Wall>({ 2.f,2.f });


	for (auto _actor : ActorsOnLevel)
	{
		_actor->BeginPlay();
	}
}
void LevelSubsystem::Update()
{
	for (auto _actor : ActorsOnLevel)
	{
		if (_actor->CanTick())
		{
			_actor->Update();
		}
	}
}
