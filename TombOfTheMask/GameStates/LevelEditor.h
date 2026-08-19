#pragma once
#include "GameState.h"

class AActor;
class UWorld;
class AEditorSpectator;
class UEditorSelectorPanel;

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
    std::unique_ptr<UEditorSelectorPanel> EditorSelectorPanel;

    AEditorSpectator* WorldSpectator;

    int selectorID = -1;
    std::string LevelName;

    FActorInfo LevelActors[LEVEL_SIZE][LEVEL_SIZE];

    void AddEntity();
    void RotateEntity();
    void RemoveEntity();
    void EndEditor();
    int x_cell, y_cell;

public:
    ULevelEditor();
    virtual void BeginPlay() override;
    virtual void Update(float deltaTime) override;

    void SaveLevel();
    void LoadLevel();

    void SelectByID(int newID);
};
