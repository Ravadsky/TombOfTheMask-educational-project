#include "LevelEditor.h"
#include "EditorObject.h"

#include "FunctionLibrary.h"
#include "GarbageCollector.h"
#include "LevelSubsystem.h"
#include "RenderSubsystem.h"
#include "ResourceSubsystem.h"

#include "Wall.h"
#include "assert.h"
#include <fstream>
#include <sstream>

LevelEditor::LevelEditor(sf::RenderWindow &window)
{
    GWindow = &window;
    GResourceSubsystem = new ResourceSubsystem();
    GLevelSubsystem = new LevelSubsystem();
    GRenderSubsystem = new RenderSubsystem();
    GGarbageCollector = new GarbageCollector();
}

void LevelEditor::BeginPlay()
{
    GLevelSubsystem->needToStartLevel = false;

    for (int i = 0; i < MAX_LEVEL_SIZE; ++i)
        for (int j = 0; j < MAX_LEVEL_SIZE; ++j)
        {
            SpawnActor<EditorObject>({(float)i, (float)j});
        }

    std::ifstream file(RESOURCES_PATH + "Levels/" + CurrentLevelName);
    std::string line;

    while (std::getline(file, line))
    {
        std::istringstream stream(line);

        int ActorID, xPos, yPos, Rotation;
        char commaSeparator;

        if (stream >> ActorID >> commaSeparator >> xPos >> commaSeparator >> yPos >> commaSeparator >> Rotation)
        {
            if (ActorID != 0)
            {
                ActorsInfo[xPos][yPos] = {ActorID, xPos, yPos, Rotation};
                Actors[xPos][yPos] =
                    GLevelSubsystem->CreateObject({(float)xPos, (float)yPos}, (float)Rotation, ActorID);
            }
        }
    }

    GRenderSubsystem->BeginPlay();
    GRenderSubsystem->SetCameraPosition(&CameraOffset);
}

void LevelEditor::Update()
{
    sf::Event event;
    while (GWindow->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            GWindow->close();
    }

    // Рассчет позиции мыши
    int xMousePos =
        (event.mouseButton.x + (int)CameraOffset.x - (int)CAMERA_PIVOT.x + SPRITE_GAME_SIZE / 2) / SPRITE_GAME_SIZE;
    int yMousePos =
        (event.mouseButton.y + (int)CameraOffset.y - (int)CAMERA_PIVOT.y + SPRITE_GAME_SIZE / 2) / SPRITE_GAME_SIZE;

    // Ограничение позиций мыши по игровому полю
    if (xMousePos < 0 or xMousePos >= MAX_LEVEL_SIZE)
        xMousePos = -1;
    if (yMousePos < 0 or yMousePos >= MAX_LEVEL_SIZE)
        yMousePos = -1;

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

    // Выбор - с каким поворотом ставить объект
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        CurrentRotationAngle = 180;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        CurrentRotationAngle = 270;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        CurrentRotationAngle = 90;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        CurrentRotationAngle = 0;

    // Перемещение камеры по уровню игры
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        CameraOffset += {0.f, -8.f};
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        CameraOffset += {0.f, 8.f};
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        CameraOffset += {-8.f, 0.f};
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        CameraOffset += {8.f, 0.f};

    // Ограничение полета камеры игровым уровнем
    float CameraX = Clamp(CameraOffset.x, MinCameraPos.x, MaxCameraPos.x);
    float CameraY = Clamp(CameraOffset.y, MinCameraPos.y, MaxCameraPos.y);
    CameraOffset = {CameraX, CameraY};

    // Установить новый объект в клетку
    if (sf::Event::MouseButtonPressed and event.mouseButton.button == sf::Mouse::Left)
    {
        if (xMousePos != -1 and yMousePos != -1 and ActorsInfo[xMousePos][yMousePos].ActorID == -1)
        {
            ActorsInfo[xMousePos][yMousePos] = {CurrentObjectIndex, xMousePos, yMousePos, CurrentRotationAngle};
            Actors[xMousePos][yMousePos] = GLevelSubsystem->CreateObject(
                {(float)xMousePos, (float)yMousePos}, (float)CurrentRotationAngle, CurrentObjectIndex);
        }
    }

    // Удалить объект из клетки
    if (sf::Event::MouseButtonPressed and event.mouseButton.button == sf::Mouse::Right)
    {
        if (xMousePos != -1 and yMousePos != -1)
        {
            ActorsInfo[xMousePos][yMousePos] = {-1, 0, 0, 0};
            if (auto actor = Actors[xMousePos][yMousePos].lock())
                actor->MarkToKill();
        }
    }

    // Сохранение игрового уровня на Enter
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
        std::ofstream file(RESOURCES_PATH + "Levels/" + CurrentLevelName);
        assert(file.is_open());

        file.clear();
        bool PlayerIsExists = false;

        for (int i = 0; i < MAX_LEVEL_SIZE; ++i)
            for (int j = 0; j < MAX_LEVEL_SIZE; ++j)
            {
                auto actor = ActorsInfo[i][j];
                if (actor.ActorID != -1)
                {
                    file << actor.ActorID << "," << actor.xPos << "," << actor.yPos << "," << actor.rotation << "\n";

                    // создание персонажа на месте ворот спавна
                    if (actor.ActorID == 8 and !PlayerIsExists)
                    {
                        file << 0 << "," << actor.xPos << "," << actor.yPos << "," << actor.rotation << "\n";
                        PlayerIsExists = true;
                    }
                }
            }
    }
    GLevelSubsystem->Update();

    GRenderSubsystem->Update();

    GGarbageCollector->Update();
}
