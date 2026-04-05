#include "CoreMinimal.h"
#include "Engine.h"
#include "LevelEditor.h"

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

int main1()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIGHT, WINDOW_HEIGHT), "Tomb of the Mask");

    window.setFramerateLimit(MAX_FPS);
    window.setVerticalSyncEnabled(true);

    LevelEditor GameLevelEditor(window);
    GameLevelEditor.BeginPlay();

    while (window.isOpen())
    {
        GameLevelEditor.Update();
    }

    return 0;
}