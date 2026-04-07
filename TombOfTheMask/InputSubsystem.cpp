#include "InputSubsystem.h"
#include "Engine.h"
#include "LevelSubsystem.h"
#include "MainMenu.h"
#include "Player.h"
InputSubsystem::InputSubsystem()
{
}

void InputSubsystem::Update()
{
    sf::Event event;
    while (GWindow->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            GWindow->close();
    }

    if (auto player = GLevelSubsystem->CurrentPlayer.lock())
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            player->SetDirection(MoveDirection::Up);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            player->SetDirection(MoveDirection::Down);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            player->SetDirection(MoveDirection::Left);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            player->SetDirection(MoveDirection::Right);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        GEngine->SwitchState<MainMenu>();
}
