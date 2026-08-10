#pragma once
#include "GameState.h"

class LevelSubsystem;
class Actor;

struct ActorInfo
{
    int ActorID = -1;
    int rotation = 0;
};

class LevelEditor : public GameState
{
  private:
    std::unique_ptr<LevelSubsystem> LevelSS;

    int CurrentObjectIndex = 1;
    std::string LevelName;

    sf::Vector2f CameraOffset = {MAX_LEVEL_SIZE / 2 * SPRITE_GAME_SIZE, MAX_LEVEL_SIZE / 2 * SPRITE_GAME_SIZE};
    const sf::Vector2f MinCameraPos = {CAMERA_PIVOT - sf::Vector2f(SPRITE_GAME_SIZE / 2, SPRITE_GAME_SIZE / 2)};
    const sf::Vector2f MaxCameraPos = {sf::Vector2f(MAX_LEVEL_SIZE * SPRITE_GAME_SIZE - SPRITE_GAME_SIZE / 2,
                                                    MAX_LEVEL_SIZE *SPRITE_GAME_SIZE - SPRITE_GAME_SIZE / 2) -
                                       CAMERA_PIVOT};

    std::weak_ptr<Actor> Actors[MAX_LEVEL_SIZE][MAX_LEVEL_SIZE];
    ActorInfo ActorsInfo[MAX_LEVEL_SIZE][MAX_LEVEL_SIZE];

  public:
    LevelEditor();
    virtual void BeginPlay() override;
    virtual void Update(float deltaTime) override;
                                                            
    void SaveLevel();
    void LoadLevel();
                        
    void MoveCamera();
    void SelectObjectIndex();
};
