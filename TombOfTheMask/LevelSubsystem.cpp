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
	ActorsID[0] = [](sf::Vector2f pos, float rotation) {return SpawnActor<Player>(pos, rotation); };
	ActorsID[1] = [](sf::Vector2f pos, float rotation) {return SpawnActor<Wall>(pos, rotation); };
	ActorsID[2] = [](sf::Vector2f pos, float rotation) {return SpawnActor<CornerWall>(pos, rotation); };
	ActorsID[3] = [](sf::Vector2f pos, float rotation) {return SpawnActor<Spikes>(pos, rotation); };
	ActorsID[4] = [](sf::Vector2f pos, float rotation) {return SpawnActor<Archer>(pos, rotation); };
	ActorsID[5] = [](sf::Vector2f pos, float rotation) {return SpawnActor<Arrow>(pos, rotation); };
	ActorsID[6] = [](sf::Vector2f pos, float rotation) {return SpawnActor<Point>(pos, rotation); };
	ActorsID[7] = [](sf::Vector2f pos, float rotation) {return SpawnActor<Star>(pos, rotation); };
	ActorsID[8] = [](sf::Vector2f pos, float rotation) {return SpawnActor<PlayerStart>(pos, rotation); };
	ActorsID[9] = [](sf::Vector2f pos, float rotation) {return SpawnActor<PlayerStartBlock>(pos, rotation); };
	ActorsID[10] = [](sf::Vector2f pos, float rotation) {return SpawnActor<PlayerEnd>(pos, rotation); };
	ActorsID[11] = [](sf::Vector2f pos, float rotation) {return SpawnActor<PlayerEndBlock>(pos, rotation); };
	ActorsID[12] = [](sf::Vector2f pos, float rotation) {return SpawnActor<BackgroundWall>(pos, rotation); };
	ActorsID[15] = [](sf::Vector2f pos, float rotation) {return SpawnActor<EditorObject>(pos, rotation); };
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

void LevelSubsystem::CreateStaticObjects()
{
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

void LevelSubsystem::CreateDynamicObjects()
{


}

std::weak_ptr<Actor> LevelSubsystem::CreateObject(sf::Vector2f pos, float rotation, int ID)
{
	return ActorsID[ID](pos, rotation);
}
