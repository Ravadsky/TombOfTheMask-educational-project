#include "LevelEditor.h"

#include "Core/GameSubsystems/AudioSubsystem.h"
#include "Core/GameSubsystems/RenderSubsystem.h"
#include "Core/GameSubsystems/ResourceSubsystem.h"
#include "Core/DataFunctions.h"
#include "Actors/Environment/EditorObject.h"
#include "Actors/Environment/Point.h"
#include "Actors/Environment/Star.h"
#include "LevelEditorSelector.h"
#include <sstream>
#include "World/World.h"
#include "Actors/EditorSpectator.h"
#include "Components/CameraComponent.h"
#include "MainMenu.h"
#include "GUI/EditorSelector.h"

void ULevelEditor::AddEntity()
{
    if (x_cell == -1 or y_cell == -1 or selectorID == -1)
        return;

    if (LevelActors[x_cell][y_cell].ActorID == -1)
    {
        LevelActors[x_cell][y_cell] = { selectorID, 0, nullptr };

        LevelActors[x_cell][y_cell].currentActor = WorldInstance->SpawnActorOnCellByID(
            LevelActors[x_cell][y_cell].ActorID, x_cell, y_cell, (float)LevelActors[x_cell][y_cell].currentRotation);
    }
}

void ULevelEditor::RotateEntity()
{
    if (x_cell == -1 or y_cell == -1)
        return;

    if (LevelActors[x_cell][y_cell].ActorID != -1)
    {
        LevelActors[x_cell][y_cell].currentActor->MarkAsGarbage();

        auto newRotation = LevelActors[x_cell][y_cell].currentRotation + 90;
        auto rotatedActor =
            WorldInstance->SpawnActorOnCellByID(LevelActors[x_cell][y_cell].ActorID, x_cell, y_cell, newRotation);

        LevelActors[x_cell][y_cell].currentActor = rotatedActor;
        LevelActors[x_cell][y_cell].currentRotation = newRotation;
    }
}

void ULevelEditor::RemoveEntity()
{
    if (x_cell == -1 or y_cell == -1)
        return;

    if (LevelActors[x_cell][y_cell].currentActor != nullptr)
        LevelActors[x_cell][y_cell].currentActor->MarkAsGarbage();

    LevelActors[x_cell][y_cell] = { -1, 0, nullptr };
}

void ULevelEditor::EndEditor()
{
    WorldInstance->DestoyLevel();
}

ULevelEditor::ULevelEditor() : UGameState()
{
    LevelName = "Level" + std::to_string(GetDataParameter("CurrentLevel:"));

    WorldInstance = std::make_unique<UWorld>();
    EditorSelectorPanel = Construct<UEditorSelectorPanel>(nullptr);

    onLeftMouseButtonPressed.Add(this, &ULevelEditor::AddEntity);
    onMiddleMouseButtonPressed.Add(this, &ULevelEditor::RotateEntity);
    onRightMouseButtonPressed.Add(this, &ULevelEditor::RemoveEntity);
    onEnterPressed.Add(this, &ULevelEditor::SaveLevel);
    onEscapePressed.Add(this, &ULevelEditor::EndEditor);
}

void ULevelEditor::BeginPlay()
{
    EditorSelectorPanel->UpdateSelectorPanel(this);

    // Создание фона
    for (int i = 0; i < LEVEL_SIZE; ++i)
        for (int j = 0; j < LEVEL_SIZE; ++j)
        {
            WorldInstance->SpawnActorOnCell<AEditorObject>(i, j, 0, { 1, 1 });
        }

    sf::Vector2f LevelCenter = { LEVEL_SIZE / 2 * SPRITE_GAME_SIZE, LEVEL_SIZE / 2 * SPRITE_GAME_SIZE };

    WorldSpectator = WorldInstance->SpawnActor<AEditorSpectator>(LevelCenter, 0);

    //  Загрузка уровня
    LoadLevel();
}

void ULevelEditor::Update(float deltaTime)
{

    auto cameraPos = WorldSpectator->GetComponentByClass<UCameraComponent>()->GetCameraPosition();
    float halfCellSize = SPRITE_GAME_SIZE / 2;
    auto mousePosition = sf::Mouse::getPosition(*Window);
    x_cell = (mousePosition.x + cameraPos.x - CAMERA_PIVOT.x + halfCellSize) / SPRITE_GAME_SIZE;
    y_cell = (mousePosition.y + cameraPos.y - CAMERA_PIVOT.y + halfCellSize) / SPRITE_GAME_SIZE;

    // Ограничение позиций мыши по игровому полю
    if (x_cell < 0 or x_cell >= LEVEL_SIZE)
        x_cell = -1;
    if (y_cell < 0 or y_cell >= LEVEL_SIZE)
        y_cell = -1;

    if (EditorSelectorPanel->IsHoveredByMouse(xMousePos, yMousePos))
    {
        x_cell = -1;
        y_cell = -1;
    }

    UGameState::Update(deltaTime);

    WorldInstance->Update(deltaTime);
}

void ULevelEditor::SaveLevel()
{
    std::ofstream file(RESOURCES_PATH + "Levels/" + LevelName + ".txt");
    assert(file.is_open());

    file.clear();

    for (int xPos = 0; xPos < LEVEL_SIZE; ++xPos)
        for (int yPos = 0; yPos < LEVEL_SIZE; ++yPos)
        {
            auto& actor = LevelActors[xPos][yPos];
            if (actor.ActorID != -1)
            {
                file << actor.ActorID << "," << xPos << "," << yPos << "," << actor.currentRotation << "\n";
            }
        }

    ChangeDataParamater("Level" + std::to_string(GetDataParameter("CurrentLevel:")) + ":", 0);

    int PointCountOnLevel = WorldInstance->GetActorsNumberOfClass<APoint>();
    ChangeDataParamater("Level" + std::to_string(GetDataParameter("CurrentLevel:")) + ".maxpoints:", PointCountOnLevel);
    ChangeDataParamater("Level" + std::to_string(GetDataParameter("CurrentLevel:")) + ".points:", 0);

    int StarCountOnLevel = WorldInstance->GetActorsNumberOfClass<AStar>();
    ChangeDataParamater("Level" + std::to_string(GetDataParameter("CurrentLevel:")) + ".maxstars:", StarCountOnLevel);
    ChangeDataParamater("Level" + std::to_string(GetDataParameter("CurrentLevel:")) + ".stars:", 0);
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
            auto spawnedActor = WorldInstance->SpawnActorOnCellByID(ActorID, xPos, yPos, (float)Rotation);
            LevelActors[xPos][yPos] = { ActorID, Rotation, spawnedActor };
        }
    }
}

void ULevelEditor::SelectByID(int newID)
{
    selectorID = newID;
}
