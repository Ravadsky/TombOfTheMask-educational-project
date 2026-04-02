#include "LevelSubsystem.h"
#include "FunctionLibrary.h"

#include "Player.h"
#include "Wall.h"
#include "Spikes.h"
#include "Point.h"
#include "Star.h"
#include "BackgroundWall.h"
#include "PlayerStart.h"
#include "Archer.h"

LevelSubsystem::LevelSubsystem()
{

}

void LevelSubsystem::BeginPlay()
{
	StartLevel();
}

void LevelSubsystem::Update()
{
	for (auto _actor : ActorsOnLevel)
	{
		if (_actor->CanTick()) _actor->Update();
	}
}

void LevelSubsystem::StartLevel()
{
	CreateBackground();
	CreateStaticObjects();
	CreateDynamicObjects();
}

void LevelSubsystem::RestartLevel()
{
	//здесь нужно удалять все динамические объекты.
	//delete CurrentPlayer;

	sf::sleep(sf::milliseconds(200));

	CreateDynamicObjects();

}

void LevelSubsystem::CreateBackground()
{
	for (int i = 1; i < 6; ++i)
	{
		for (int j = 1; j < 6; ++j)
		{
			SpawnActor<BackgroundWall>({ (float)i, (float)j });
		}
	}
}

void LevelSubsystem::CreateStaticObjects()
{
	SpawnActor<Wall>({ 1.f,1.f });
	SpawnActor<Wall>({ 1.f,2.f });
	SpawnActor<Spikes>({ 1.f,3.f });
	SpawnActor<Archer>({ 1.f,4.f });
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

	SpawnActor<PlayerStart>({ 3.f,3.f });
}

void LevelSubsystem::CreateDynamicObjects()
{
	CurrentPlayer = SpawnActor<Player>({ 3.f, 3.f }, 0.f);

	SpawnActor<Point>({ 4.f,4.f });
	SpawnActor<Star>({ 4.f,3.f });

}
