#pragma once
#include "GameState.h"

class AActor;
class UWorld;
class AEditorSpectator;

struct FActorInfo
{
    int ActorID = -1;
    int currentRotation = 0;
    AActor* currentActor = nullptr;
};

class ULevelEditor : public UGameState
{
private:
    std::unique_ptr<UWorld> WorldInstance;
    AEditorSpectator* WorldSpectator;

    int CurrentObjectIndex = 1;
    std::string LevelName;

    FActorInfo LevelActors[LEVEL_SIZE][LEVEL_SIZE];

    void AddEntity();
    void RotateEntity();
    void RemoveEntity();

    int xCellMousePos, yCellMousePos;

public:
    ULevelEditor();
    virtual void BeginPlay() override;
    virtual void Update(float deltaTime) override;

    void SaveLevel();
    void LoadLevel();

    void SelectObjectIndex();
};
