#pragma once
#include "UObject.h"
#include "Actor.h"

struct ActorInfo
{
	int ActorID = -1;
	int xPos = 0;
	int yPos = 0;
	int rotation = 0;
};

class LevelEditor : public UObject
{
private:
	int CurrentObjectIndex = 1;
	int CurrentRotationAngle = 0;

	std::weak_ptr<Actor> Actors[100][100];
	ActorInfo ActorsInfo[100][100];

public:
	LevelEditor(sf::RenderWindow& window);

	void BeginPlay() override;
	void Update() override;
};

