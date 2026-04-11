#include "CoreMinimal.h"
#include "Engine.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIGHT, WINDOW_HEIGHT), "Tomb of the Mask");
    window.setFramerateLimit(MAX_FPS);
    window.setVerticalSyncEnabled(true);
    GWindow = &window;

    GEngine = new Engine();

    while (window.isOpen())
    {
        GEngine->Update();
    }

    return 0;
}