#include "MainMenu.h"
#include "Core/DataFunctions.h"
#include "Core/GameSubsystems/AudioSubsystem.h"

#include "GUI/Button.h"
#include "GUI/CheckBox.h"
#include "GUI/Base/Image.h"

#include "LevelSelector.h"
#include "LevelEditorSelector.h"

UMainMenu::UMainMenu() : UGameState()
{
    float CentralWidth = WINDOW_WIGHT / 2;

    CanvasImage = Construct<UImage>(nullptr);
    CanvasImage->SetTextureByName("background");

    StartGameButton = ConstructButton<UButton>(CanvasImage.get(), "Start");
    StartGameButton->onButtonPressed.Add(this, &UMainMenu::StartGameButtonPressed);
    StartGameButton->SetScreenPosition({ 0.0f, -192.0f });

    EditorButton = ConstructButton<UButton>(CanvasImage.get(), "Editor");
    EditorButton->onButtonPressed.Add(this, &UMainMenu::EditorButtonPressed);

    ExitButton = ConstructButton<UButton>(CanvasImage.get(), "Exit");
    ExitButton->onButtonPressed.Add(this, &UMainMenu::ExitButtonPressed);
    ExitButton->SetScreenPosition({ 0.0f, +192.0f });

    SoundBox = ConstructButton<UCheckBox>(CanvasImage.get(), "");
    SoundBox->onButtonPressed.Add(this, &UMainMenu::SoundBoxChanged);
    SoundBox->SetTextureNames("sound_on", "sound_off");
    SoundBox->SetInitState(GetDataParameter("SoundValue:"));
    SoundBox->SetScreenPosition({ 96, +96 });

    MusicBox = ConstructButton<UCheckBox>(CanvasImage.get(), "");
    MusicBox->onButtonPressed.Add(this, &UMainMenu::MusicBoxChanged);
    MusicBox->SetTextureNames("music_on", "music_off");
    MusicBox->SetInitState(GetDataParameter("MusicValue:"));
    MusicBox->SetScreenPosition({ 96, +256 });
}

void UMainMenu::StartGameButtonPressed()
{
    Engine->MarkToSwitchState<ULevelSelector>();
}

void UMainMenu::EditorButtonPressed()
{
    Engine->MarkToSwitchState<ULevelEditorSelector>();
}

void UMainMenu::ExitButtonPressed()
{
    Window->close();
}

void UMainMenu::SoundBoxChanged()
{
    ChangeDataParamater("SoundValue:", SoundBox->ChangeState());
    GetAudioSubsystem()->UpdateSoundAndMusicValues();
}

void UMainMenu::MusicBoxChanged()
{
    ChangeDataParamater("MusicValue:", MusicBox->ChangeState());
    GetAudioSubsystem()->UpdateSoundAndMusicValues();
}
