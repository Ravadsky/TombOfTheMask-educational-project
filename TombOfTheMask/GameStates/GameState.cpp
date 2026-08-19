#include "GameState.h"
#include "GUI/Button.h"
#include "GameStates/MainMenu.h"
#include "Core/GameSubsystems/AudioSubsystem.h"

UGameState::UGameState() : UObject()
{
    GetAudioSubsystem()->UpdateSoundAndMusicValues();
    GetAudioSubsystem()->StartNewMusic("menu_music");

    onLeftMouseButtonPressed.Add(this, &UGameState::CheckAllButtonsPressed);
    onEscapePressed.Add(this, &UGameState::ReturnToMainMenu);
}

void UGameState::Update(float deltaTime)
{
    xMousePos = sf::Mouse::getPosition(*Window).x;
    yMousePos = sf::Mouse::getPosition(*Window).y;

    sf::Event event;

    while (Window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            Window->close();

        if (event.type == sf::Event::MouseButtonPressed)
        {
            if (event.mouseButton.button == sf::Mouse::Left)
                onLeftMouseButtonPressed.Broadcast();

            if (event.mouseButton.button == sf::Mouse::Middle)
                onMiddleMouseButtonPressed.Broadcast();

            if (event.mouseButton.button == sf::Mouse::Right)
                onRightMouseButtonPressed.Broadcast();
        }

        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Enter)
                onEnterPressed.Broadcast();

            if (event.key.code == sf::Keyboard::Escape)
                onEscapePressed.Broadcast();
        }
    }
}

void UGameState::CheckAllButtonsPressed()
{
    for (auto button : Buttons)
        button->TriggerIfCollision(xMousePos, yMousePos);
}

void UGameState::ReturnToMainMenu()
{
    Engine->MarkToSwitchState<UMainMenu>();
}
