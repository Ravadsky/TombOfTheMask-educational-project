#include "LevelSubsystem.h"
#include "FunctionLibrary.h"
#include <fstream>
#include <sstream>

#include "Player.h"
#include "Wall.h"
#include "Spikes.h"
#include "Point.h"
#include "Star.h"
#include "Arrow.h"
#include "BackgroundWall.h"
#include "PlayerStart.h"
#include "Archer.h"
#include "CornerWall.h"
#include "EditorObject.h"
#include "PlayerStartBlock.h"
#include "PlayerEndBlock.h"
#include "PlayerEnd.h"


LevelSubsystem::LevelSubsystem()
{
	AddBindActorID<Player>(0);
	AddBindActorID<Wall>(1);
	AddBindActorID<CornerWall>(2);
	AddBindActorID<Spikes>(3);
	AddBindActorID<Archer>(4);
	AddBindActorID<Arrow>(5);
	AddBindActorID<Point>(6);
	AddBindActorID<Star>(7);
	AddBindActorID<PlayerStart>(8);
	AddBindActorID<PlayerStartBlock>(9);
	AddBindActorID<PlayerEnd>(10);
	AddBindActorID<PlayerEndBlock>(11);
	AddBindActorID<BackgroundWall>(12);
	AddBindActorID<EditorObject>(15);
}

void LevelSubsystem::BeginPlay()
{

}

void LevelSubsystem::Update()
{
	CheckStartingLevel();

	for (auto _actor : ActorsOnLevel)
	{
		if (_actor->CanTick()) _actor->Update();
	}
}

void LevelSubsystem::CheckStartingLevel()
{
	if (needToStartLevel)
	{
		if (Timer<LevelSubsystem>(0.4f))
		{
			for (auto _actor : ActorsOnLevel)
			{
				_actor->MarkToKill();
			}

			needToStartLevel = false;
			std::ifstream file(RESOURCES_PATH + "Levels/" + "Level1.txt");
			std::string line;
			while (std::getline(file, line))
			{
				std::istringstream stream(line);
				int xPos, yPos, Rotation, ActorID;
				char commaSeparator;

				stream >> ActorID >> commaSeparator >> xPos >> commaSeparator >> yPos >> commaSeparator >> Rotation;

				CreateObject({ (float)xPos, (float)yPos }, (float)Rotation, ActorID);
			}
		}
	}
}

std::weak_ptr<Actor> LevelSubsystem::CreateObject(sf::Vector2f pos, float rotation, int ID)
{
	return ActorsID[ID](pos, rotation);
}
