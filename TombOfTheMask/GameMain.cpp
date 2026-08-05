#include "CoreMinimal.h"
#include "Engine.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIGHT, WINDOW_HEIGHT), "Tomb of the Mask");
    window.setFramerateLimit(MAX_FPS);
    window.setVerticalSyncEnabled(true);
    GWindow = &window;

    GetEngine = new GEngine();

    while (window.isOpen())
    {
        GetEngine->Update();
    }

    return 0;
}