#include "LevelEditorSelector.h"

#include "Core/GameSubsystems/AudioSubsystem.h"
#include "GUI/Button.h"
#include "Core/DataFunctions.h"
#include "LevelEditor.h"
#include "MainMenu.h"

void ULevelEditorSelector::OnLevel1ButtonPressed()
{
    ChooseLevel(1);
}

void ULevelEditorSelector::OnLevel2ButtonPressed()
{
    ChooseLevel(2);
}

void ULevelEditorSelector::OnLevel3ButtonPressed()
{
    ChooseLevel(3);
}

ULevelEditorSelector::ULevelEditorSelector()
{
    GetAudioSubsystem()->StartNewMusic("menu_music");

    float CentralWidth = WINDOW_WIGHT / 2;
    Level1Button = std::make_unique<UButton>("Level 1");
    Level1Button->onButtonPressed.Add(this, &ULevelEditorSelector::OnLevel1ButtonPressed);

    Level2Button = std::make_unique<UButton>("Level 2");
    Level2Button->onButtonPressed.Add(this, &ULevelEditorSelector::OnLevel2ButtonPressed);

    Level3Button = std::make_unique<UButton>("Level 3");
    Level3Button->onButtonPressed.Add(this, &ULevelEditorSelector::OnLevel3ButtonPressed);
}

void ULevelEditorSelector::Update(float deltaTime)
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
            Level1Button->TriggerIfCollision(xMousePos, yMousePos);
            Level2Button->TriggerIfCollision(xMousePos, yMousePos);
            Level3Button->TriggerIfCollision(xMousePos, yMousePos);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            Engine->MarkToSwitchState<UMainMenu>();
        }
    }
}

void ULevelEditorSelector::ChooseLevel(int index)
{
    GetAudioSubsystem()->PlaySound("button_sound");

    Engine->MarkToSwitchState<LevelEditor>();
    ChangeDataParamater("CurrentLevel:", index);
}
