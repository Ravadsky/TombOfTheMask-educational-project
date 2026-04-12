#include "LevelSubsystem.h"

#include "ResourceSubsystem.h"
#include <sstream>
#include "Point.h"
#include "Star.h"
#include "DataFunctions.h"

LevelSubsystem::LevelSubsystem()
{
    PointCountOnLevel = 0;
    StarCountOnLevel = 0;
}

void LevelSubsystem::Update()
{
    for (auto _actor : ActorsOnLevel)
    {
        if (_actor->CanTick())
            _actor->Update();
    }
}

std::weak_ptr<Actor> LevelSubsystem::CreateObject(sf::Vector2f pos, float rotation, int ID)
{
    return GResourceSubsystem->ActorsID[ID](pos, rotation);
}

void LevelSubsystem::StartLevel()
{
    LevelName = "Level" + std::to_string(GetDataParameter("CurrentLevel:"));
    std::ifstream file(RESOURCES_PATH + "Levels/" + LevelName + ".txt");

    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream stream(line);
        int xPos, yPos, Rotation, ActorID;
        char commaSeparator;

        stream >> ActorID >> commaSeparator >> xPos >> commaSeparator >> yPos >> commaSeparator >> Rotation;

        CreateObject({(float)xPos, (float)yPos}, (float)Rotation, ActorID);

        if (ActorID == 6 or ActorID == 7)
        {
            CreateObject({(float)xPos, (float)yPos}, 0, 12);
        }
    }

    PointCountOnLevel = GetCountOfActorsOf<Point>();
    StarCountOnLevel = GetCountOfActorsOf<Star>();

    for (auto _actor : ActorsOnLevel)
    {
        _actor->BeginPlay();
    }
}
