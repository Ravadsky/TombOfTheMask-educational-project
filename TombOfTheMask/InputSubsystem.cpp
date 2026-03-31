#include "InputSubsystem.h"

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
}
