#include "LevelEditor.h"

#include "Core/GameSubsystems/AudioSubsystem.h"
#include "Core/GameSubsystems/RenderSubsystem.h"
#include "Core/GameSubsystems/ResourceSubsystem.h"
#include "Core/DataFunctions.h"
#include "Actors/Environment/EditorObject.h"
#include "Actors/Point.h"
#include "Actors/Star.h"
#include "LevelEditorSelector.h"
#include <sstream>
#include "World/World.h"
#include "Actors/EditorSpectator.h"
#include "Components/CameraComponent.h"

void ULevelEditor::AddEntity()
{
    if (xCellMousePos != -1 and yCellMousePos != -1 and LevelActors[xCellMousePos][yCellMousePos].ActorID == -1)
    {
        LevelActors[xCellMousePos][yCellMousePos] = { CurrentObjectIndex, 0, nullptr };

        LevelActors[xCellMousePos][yCellMousePos].currentActor = WorldInstance->SpawnActorOnCellByID(
            LevelActors[xCellMousePos][yCellMousePos].ActorID, xCellMousePos, yCellMousePos,
            (float)LevelActors[xCellMousePos][yCellMousePos].currentRotation);
    }
}

void ULevelEditor::RotateEntity()
{
    if (xCellMousePos != -1 and yCellMousePos != -1 and LevelActors[xCellMousePos][yCellMousePos].ActorID != -1)
    {
        LevelActors[xCellMousePos][yCellMousePos] = { LevelActors[xCellMousePos][yCellMousePos].ActorID,
                                                      LevelActors[xCellMousePos][yCellMousePos].currentRotation + 90 };

        if (auto actor = LevelActors[xCellMousePos][yCellMousePos].currentActor)
        {
            actor->MarkAsGarbage();
        }

        LevelActors[xCellMousePos][yCellMousePos].currentActor = WorldInstance->SpawnActorOnCellByID(
            LevelActors[xCellMousePos][yCellMousePos].ActorID, xCellMousePos, yCellMousePos,
            (float)LevelActors[xCellMousePos][yCellMousePos].currentRotation);
    }
}

void ULevelEditor::RemoveEntity()
{
    if (xCellMousePos != -1 and yCellMousePos != -1)
    {
        if (LevelActors[xCellMousePos][yCellMousePos].currentActor != nullptr)
            LevelActors[xCellMousePos][yCellMousePos].currentActor->MarkAsGarbage();

        LevelActors[xCellMousePos][yCellMousePos] = { -1, 0, nullptr };
    }
}

ULevelEditor::ULevelEditor() : UGameState()
{
    LevelName = "Level" + std::to_string(GetDataParameter("CurrentLevel:"));

    WorldInstance = std::make_unique<UWorld>();
}

void ULevelEditor::BeginPlay()
{
    // Создание фона
    for (int i = 0; i < LEVEL_SIZE; ++i)
        for (int j = 0; j < LEVEL_SIZE; ++j)
        {
            WorldInstance->SpawnActorOnCell<AEditorObject>(i, j, 0, { 1, 1 });
        }

    sf::Vector2f LevelCenter = { LEVEL_SIZE / 2 * SPRITE_GAME_SIZE, LEVEL_SIZE / 2 * SPRITE_GAME_SIZE };

    WorldSpectator = WorldInstance->SpawnActor<AEditorSpectator>(LevelCenter, 0);
    //  Загрузка уровня
    //  LoadLevel();
}

void ULevelEditor::Update(float deltaTime)
{
    UGameState::Update(deltaTime);

    WorldInstance->Update(deltaTime);

    auto cameraPos = WorldSpectator->GetComponentByClass<UCameraComponent>()->GetCameraPosition();
    float halfCellSize = SPRITE_GAME_SIZE / 2;
    auto mousePosition = sf::Mouse::getPosition(*Window);
    xCellMousePos = (mousePosition.x + cameraPos.x - CAMERA_PIVOT.x + halfCellSize) / SPRITE_GAME_SIZE;
    yCellMousePos = (mousePosition.y + cameraPos.y - CAMERA_PIVOT.y + halfCellSize) / SPRITE_GAME_SIZE;

    // Ограничение позиций мыши по игровому полю
    if (xCellMousePos < 0 or xCellMousePos >= LEVEL_SIZE)
        xCellMousePos = -1;
    if (yCellMousePos < 0 or yCellMousePos >= LEVEL_SIZE)
        yCellMousePos = -1;

    SelectObjectIndex();

    if (sf::Mouse::isButtonPressed(sf::Mouse::Middle))
        RotateEntity();

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        AddEntity();

    if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
        RemoveEntity();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
        SaveLevel();
}

void ULevelEditor::SaveLevel()
{
    std::ofstream file(RESOURCES_PATH + "Levels/" + LevelName + ".txt");
    assert(file.is_open());

    file.clear();
    bool PlayerIsExists = false;

    for (int xPos = 0; xPos < LEVEL_SIZE; ++xPos)
        for (int yPos = 0; yPos < LEVEL_SIZE; ++yPos)
        {
            auto& actor = LevelActors[xPos][yPos];
            if (actor.ActorID != -1)
            {
                file << actor.ActorID << "," << xPos << "," << yPos << "," << actor.currentRotation << "\n";

                // создание персонажа на месте ворот спавна
                if (actor.ActorID == 8 and !PlayerIsExists)
                {
                    file << 0 << "," << xPos << "," << yPos << "," << 0 << "\n";
                    PlayerIsExists = true;
                }
            }
        }

    int PointCountOnLevel = WorldInstance->GetActorsNumberOfClass<APoint>();
    ChangeDataParamater("Level" + std::to_string(GetDataParameter("CurrentLevel:")) + ".maxpoints:", PointCountOnLevel);

    int StarCountOnLevel = WorldInstance->GetActorsNumberOfClass<AStar>();
    ChangeDataParamater("Level" + std::to_string(GetDataParameter("CurrentLevel:")) + ".maxstars:", StarCountOnLevel);
}

void ULevelEditor::LoadLevel()
{
    std::ifstream file(RESOURCES_PATH + "Levels/" + LevelName + ".txt");
    std::string line;

    while (std::getline(file, line))
    {
        std::istringstream stream(line);

        int ActorID, xPos, yPos, Rotation;
        char Separator;

        if (stream >> ActorID >> Separator >> xPos >> Separator >> yPos >> Separator >> Rotation)
        {
            if (ActorID != 0)
            {
                LevelActors[xPos][yPos] = { ActorID, Rotation, nullptr };

                WorldInstance->SpawnActorOnCellByID(ActorID, xPos, yPos, (float)Rotation);
            }
        }
    }
}

void ULevelEditor::SelectObjectIndex()
{
    // Выбор - какой объект ставить
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
        CurrentObjectIndex = 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
        CurrentObjectIndex = 2;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
        CurrentObjectIndex = 3;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
        CurrentObjectIndex = 4;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
        CurrentObjectIndex = 6;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7))
        CurrentObjectIndex = 7;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8))
        CurrentObjectIndex = 8;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9))
        CurrentObjectIndex = 9;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0))
        CurrentObjectIndex = 10;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Dash))
        CurrentObjectIndex = 11;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Equal))
        CurrentObjectIndex = 12;
}