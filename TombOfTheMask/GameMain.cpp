#include "Core/CoreMinimal.h"
#include "GameStates/MainMenu.h"

int main()
{
    sf::RenderWindow gameWindow(GAME_VIDEOMODE, GAME_NAME);
    gameWindow.setFramerateLimit(MAX_FPS);
    gameWindow.setVerticalSyncEnabled(true);
    Window = &gameWindow;
    
    Engine = new GEngine();
    Engine->RegisterSubsystems();
    Engine->MarkToSwitchState<UMainMenu>();

    while (Window->isOpen())
    {
        Engine->Update();
    }

    return 0;
}