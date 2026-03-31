#include "CoreMinimal.h"
#include "Engine.h"
#include "InputSubsystem.h"
#include "RenderSubsystem.h"
#include "Actor.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIGHT, WINDOW_HEIGHT), "Tomb of the Mask");
	window.setFramerateLimit(MAX_FPS);
	window.setVerticalSyncEnabled(true);

	Engine GameEngine(window);
	
	GameEngine.BeginPlay();

	while (window.isOpen())
	{
		GameEngine.Update();
	}		

	return 0;
}