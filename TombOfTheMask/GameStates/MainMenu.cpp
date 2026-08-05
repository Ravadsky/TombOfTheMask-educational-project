#include "MainMenu.h"

#include "AudioSubsystem.h"
#include "Button.h"
#include "CheckBox.h"
#include "DataFunctions.h"

#include "LevelSelector.h"
#include "LevelEditorSelector.h"
#include "Engine.h"

MainMenu::MainMenu()
{
    assert(BackgroundTexture.loadFromFile(RESOURCES_PATH + "GUI/Background.png"));
    Background = std::make_unique<SpriteComponent>(BackgroundTexture, CAMERA_PIVOT);
    Background->SetDrawType(DrawType::Widget);

    float CentralWidth = WINDOW_WIGHT / 2;
    StartGameButton = std::make_unique<Button>("Start", sf::Vector2f(CentralWidth, 200.f));
    EditorButton = std::make_unique<Button>("Editor", sf::Vector2f(CentralWidth, 400.f));
    ExitButton = std::make_unique<Button>("Exit", sf::Vector2f(CentralWidth, 600.f));

    SoundBox = std::make_unique<CheckBox>("SoundOn", "SoundOff", sf::Vector2f(96.f, 96.f));
    SoundBox->SetInitState(GetDataParameter("SoundValue:"));

    MusicBox = std::make_unique<CheckBox>("MusicOn", "MusicOff", sf::Vector2f(96.f, 256.f));
    MusicBox->SetInitState(GetDataParameter("MusicValue:"));

    GAudioSubsystem->StartNewMusic("menu_music");
}

void MainMenu::Update()
{
    sf::Event event;
    // Рассчет позиции мыши
    int xMousePos = sf::Mouse::getPosition(*GWindow).x;
    int yMousePos = sf::Mouse::getPosition(*GWindow).y;

    while (GWindow->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            GWindow->close();

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            // Проверка основных функциональных кнопок
            if (ExitButton->CheckWithCollisions(xMousePos, yMousePos))
            {
                GWindow->close();
            }
            if (StartGameButton->CheckWithCollisions(xMousePos, yMousePos))
            {
                GetEngine->SwitchState<LevelSelector>();
                GAudioSubsystem->CreateNewSound("button_sound");
            }
            if (EditorButton->CheckWithCollisions(xMousePos, yMousePos))
            {
                GetEngine->SwitchState<LevelEditorSelector>();
                GAudioSubsystem->CreateNewSound("button_sound");
            }
            // Проверка чек-боксов звуков и музыки
            if (SoundBox->CheckWithCollisions(xMousePos, yMousePos))
            {
                ChangeDataParamater("SoundValue:", SoundBox->ChangeState());
                GAudioSubsystem->UpdateSoundAndMusicValues();
                GAudioSubsystem->CreateNewSound("button_sound");
                
            }
            if (MusicBox->CheckWithCollisions(xMousePos, yMousePos))
            {
                ChangeDataParamater("MusicValue:", MusicBox->ChangeState());
                GAudioSubsystem->UpdateSoundAndMusicValues();
                GAudioSubsystem->CreateNewSound("button_sound");
            }



        }
    }
}
