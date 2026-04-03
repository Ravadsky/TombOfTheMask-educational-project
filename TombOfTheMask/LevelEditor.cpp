#include "LevelEditor.h"
#include "EditorObject.h"

#include "LevelSubsystem.h"
#include "RenderSubsystem.h"
#include "ResourceSubsystem.h"
#include "FunctionLibrary.h"

#include <fstream>
#include <sstream>	
#include "Wall.h"

LevelEditor::LevelEditor(sf::RenderWindow& window)
{
	GWindow = &window;
	GResourceSubsystem = new ResourceSubsystem();
	GLevelSubsystem = new LevelSubsystem();
	GRenderSubsystem = new RenderSubsystem();
}

void LevelEditor::BeginPlay()
{
	for (int i = 0; i < 100; ++i)
	{
		for (int j = 0; j < 100; ++j)
		{

			SpawnActor<EditorObject>({ (float)i, (float)j });
		}
	}

	std::ifstream file(RESOURCES_PATH + "Levels/" + "Level1.txt");
	std::string line;
	while (std::getline(file, line))
	{
		std::istringstream stream(line);
		int ActorID, xPos, yPos, Rotation;
		char commaSeparator;

		if (stream >> ActorID >> commaSeparator >> xPos >> commaSeparator >> yPos >> commaSeparator >> Rotation)
		{
			ActorsInfo[xPos][yPos] = { ActorID, xPos, yPos, Rotation };
			Actors[xPos][yPos] = GLevelSubsystem->CreateObject({ (float)xPos, (float)yPos }, (float)Rotation, ActorID);
		}
		
	}

	GRenderSubsystem->BeginPlay();
}

void LevelEditor::Update()
{
	sf::Event event;
	while (GWindow->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			GWindow->close();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) CurrentObjectIndex = 1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) CurrentObjectIndex = 2;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) CurrentObjectIndex = 3;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) CurrentObjectIndex = 4;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6)) CurrentObjectIndex = 6;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7)) CurrentObjectIndex = 7;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8)) CurrentObjectIndex = 8;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9)) CurrentObjectIndex = 9;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0)) CurrentObjectIndex = 10;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Dash)) CurrentObjectIndex = 11;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Equal)) CurrentObjectIndex = 12;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) CurrentRotationAngle = 180;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) CurrentRotationAngle = 270;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) CurrentRotationAngle = 90;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) CurrentRotationAngle = 0;


	if (sf::Event::MouseButtonPressed)
	{
		int x = (event.mouseButton.x + SPRITE_GAME_SIZE / 2) / SPRITE_GAME_SIZE;
		int y = (event.mouseButton.y + SPRITE_GAME_SIZE / 2) / SPRITE_GAME_SIZE;
		if (x >= 0 and x < 100 and y >= 0 and y < 100)
		{

		ActorsInfo[x][y] = { CurrentObjectIndex, x, y, CurrentRotationAngle };
		Actors[x][y] = GLevelSubsystem->CreateObject({ (float)x, (float)y }, (float)CurrentRotationAngle, CurrentObjectIndex);
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
		std::ofstream file(RESOURCES_PATH + "Levels/" + "Level1.txt");

		if (file.is_open())
		{
			file.clear();

			bool PlayerIsExists = false;

			for (int i = 0; i < 100; ++i)
			{
				for (int j = 0; j < 100; ++j)
				{
					if (ActorsInfo[i][j].ActorID != -1)
					{
						//создание персонажа на месте ворот спавна
						if (ActorsInfo[i][j].ActorID == 8 and !PlayerIsExists)
						{
							PlayerIsExists = true;
							file << 0 << "," << ActorsInfo[i][j].xPos << "," << ActorsInfo[i][j].yPos << "," << ActorsInfo[i][j].rotation << "\n";
						}

						file << ActorsInfo[i][j].ActorID << "," << ActorsInfo[i][j].xPos << "," << ActorsInfo[i][j].yPos << "," << ActorsInfo[i][j].rotation << "\n";
					}
				}
			}

		}

	}
	GLevelSubsystem->Update();

	GRenderSubsystem->Update();

}
