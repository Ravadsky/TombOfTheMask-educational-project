#include "MainMenu.h"
#include "Core/DataFunctions.h"
#include "Core/GameSubsystems/AudioSubsystem.h"
#include "GUI/Button.h"
#include "GUI/CheckBox.h"

#include "LevelSelector.h"
#include "LevelEditorSelector.h"

void UMainMenu::StartGameButtonPressed()
{
    Engine->MarkToSwitchState<LevelSelector>();
}

void UMainMenu::EditorButtonPressed()
{
    Engine->MarkToSwitchState<LevelEditorSelector>();
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

UMainMenu::UMainMenu()
{
    float CentralWidth = WINDOW_WIGHT / 2;
    GetAudioSubsystem()->StartNewMusic("menu_music");

    StartGameButton = std::make_unique<UButton>("Start");
    StartGameButton->onButtonPressed.Add(this, &UMainMenu::StartGameButtonPressed);

    EditorButton = std::make_unique<UButton>("Editor");
    EditorButton->onButtonPressed.Add(this, &UMainMenu::EditorButtonPressed);

    ExitButton = std::make_unique<UButton>("Exit");
    ExitButton->onButtonPressed.Add(this, &UMainMenu::ExitButtonPressed);

    SoundBox = std::make_unique<UCheckBox>("SoundOn", "SoundOff");
    SoundBox->SetInitState(GetDataParameter("SoundValue:"));
    SoundBox->onCheckBoxPressed.Add(this, &UMainMenu::SoundBoxChanged);

    MusicBox = std::make_unique<UCheckBox>("MusicOn", "MusicOff");
    MusicBox->SetInitState(GetDataParameter("MusicValue:"));
    MusicBox->onCheckBoxPressed.Add(this, &UMainMenu::MusicBoxChanged);
}

void UMainMenu::Update(float deltaTime)
{
    sf::Event event;
    // Рассчет позиции мыши
    int xMousePos = sf::Mouse::getPosition(*Window).x;
    int yMousePos = sf::Mouse::getPosition(*Window).y;

    while (Window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            Window->close();

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            // Проверка основных функциональных кнопок
            ExitButton->TriggerIfCollision(xMousePos, yMousePos);
            EditorButton->TriggerIfCollision(xMousePos, yMousePos);
            StartGameButton->TriggerIfCollision(xMousePos, yMousePos);

            // Проверка чек-боксов звуков и музыки
            SoundBox->TriggerIfCollision(xMousePos, yMousePos);
            MusicBox->TriggerIfCollision(xMousePos, yMousePos);
        }
    }
}
