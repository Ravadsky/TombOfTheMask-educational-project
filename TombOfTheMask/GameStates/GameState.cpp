#include "GameState.h"
#include "GUI/Button.h"
#include "GameStates/MainMenu.h"
#include "Core/GameSubsystems/AudioSubsystem.h"

UGameState::UGameState() : UObject()
{
    GetAudioSubsystem()->StartNewMusic("menu_music");
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
            {
                for (auto button : Buttons)
                    button->TriggerIfCollision(xMousePos, yMousePos);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                Engine->MarkToSwitchState<UMainMenu>();
            }
        }
    }
}
