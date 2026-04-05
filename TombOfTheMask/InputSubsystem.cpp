#include "InputSubsystem.h"
#include "LevelSubsystem.h"
#include "Player.h"

InputSubsystem::InputSubsystem()
{
}

void InputSubsystem::BeginPlay()
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
}
