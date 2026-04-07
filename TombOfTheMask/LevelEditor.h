#pragma once
#include "Actor.h"
#include "UObject.h"
#include <string>
#include "GameState.h"

struct ActorInfo
{
    int ActorID = -1;
    int xPos = 0;
    int yPos = 0;
    int rotation = 0;
};

class LevelEditor : public GameState
{
  private:
    std::unique_ptr<LevelSubsystem> LevelSS;
    std::unique_ptr<RenderSubsystem> RenderSS;

    int CurrentObjectIndex = 1;
    int CurrentRotationAngle = 0;
    std::string CurrentLevelName = "level1.txt";

    sf::Vector2f CameraOffset = {MAX_LEVEL_SIZE / 2 * SPRITE_GAME_SIZE, MAX_LEVEL_SIZE / 2 * SPRITE_GAME_SIZE};
    const sf::Vector2f MinCameraPos = {CAMERA_PIVOT - sf::Vector2f(SPRITE_GAME_SIZE / 2, SPRITE_GAME_SIZE / 2)};
    const sf::Vector2f MaxCameraPos = {sf::Vector2f(MAX_LEVEL_SIZE * SPRITE_GAME_SIZE - SPRITE_GAME_SIZE / 2,
                                                    MAX_LEVEL_SIZE *SPRITE_GAME_SIZE - SPRITE_GAME_SIZE / 2) -
                                       CAMERA_PIVOT};

    std::weak_ptr<Actor> Actors[MAX_LEVEL_SIZE][MAX_LEVEL_SIZE];
    ActorInfo ActorsInfo[MAX_LEVEL_SIZE][MAX_LEVEL_SIZE];

  public:
    LevelEditor();
    void BeginPlay() override;
    void Update() override;

    void SaveLevel();
    void LoadLevel();

    void MoveCamera();
    void SelectObjectIndex();
    void SelectObjectRotation();
};
