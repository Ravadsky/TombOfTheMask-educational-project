#include "CoreMinimal.h"
#include "Engine.h"
#include "LevelEditor.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIGHT, WINDOW_HEIGHT), "Tomb of the Mask");
	window.setFramerateLimit(MAX_FPS);
	window.setVerticalSyncEnabled(true);

	const bool LevelEditorMode = false;

	if (LevelEditorMode)
	{
		LevelEditor GameLevelEditor(window);
		GameLevelEditor.BeginPlay();

		while (window.isOpen())
		{
			GameLevelEditor.Update();
		}
	}
	else
	{
		Engine GameEngine(window);
		GameEngine.BeginPlay();

		while (window.isOpen())
		{
			GameEngine.Update();
		}
	}
	

	

	return 0;
}