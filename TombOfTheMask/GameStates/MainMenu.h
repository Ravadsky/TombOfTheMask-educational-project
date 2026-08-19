#pragma once
#include "GameState.h"

class UButton;
class UCheckBox;
class UImage;

class UMainMenu : public UGameState
{
public:
    UMainMenu();

private:
    std::unique_ptr<UImage> CanvasImage;

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
};
