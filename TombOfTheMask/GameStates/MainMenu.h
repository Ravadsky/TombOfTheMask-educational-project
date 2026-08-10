#pragma once
#include "GameState.h"

class UButton;
class UCheckBox;

class UMainMenu : public UGameState
{
private:
    std::unique_ptr<UButton> StartGameButton;
    void StartGameButtonPressed();

    std::unique_ptr<UButton> EditorButton;
    void EditorButtonPressed();

    std::unique_ptr<UButton> ExitButton;
    void ExitButtonPressed();

    std::unique_ptr<UCheckBox> SoundBox;
    void SoundBoxChanged();

    std::unique_ptr<UCheckBox> MusicBox;
    void MusicBoxChanged();

public:
    UMainMenu();

    virtual void Update(float deltaTime) override;
};
