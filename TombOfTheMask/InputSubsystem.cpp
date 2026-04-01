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

		if (event.key.code == sf::Keyboard::W)
		{
			GLevelSubsystem->CurrentPlayer->SetDirection(MoveDirection::Up);
		}
		if (event.key.code == sf::Keyboard::S)
		{
			GLevelSubsystem->CurrentPlayer->SetDirection(MoveDirection::Down);
		}
		if (event.key.code == sf::Keyboard::A)
		{
			GLevelSubsystem->CurrentPlayer->SetDirection(MoveDirection::Left);
		}
		if (event.key.code == sf::Keyboard::D)
		{
			GLevelSubsystem->CurrentPlayer->SetDirection(MoveDirection::Right);
		}

	}
}	
