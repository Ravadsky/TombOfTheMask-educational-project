#include "Core/CoreMinimal.h"

int main()
{
    sf::RenderWindow gameWindow(GAME_VIDEOMODE, GAME_NAME);
    gameWindow.setFramerateLimit(MAX_FPS);
    gameWindow.setVerticalSyncEnabled(true);
    Window = &gameWindow;

    Engine = new GEngine();

    while (Window->isOpen())
    {
        Engine->Update();
    }

    return 0;
}