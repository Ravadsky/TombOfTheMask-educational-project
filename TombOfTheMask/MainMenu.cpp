#include "MainMenu.h"
#include "AudioSubsystem.h"
#include "Engine.h"
#include "LevelEditor.h"
#include "LevelInstance.h"
#include "RenderSubsystem.h"
#include "LevelSelector.h"
#include "LevelEditorSelector.h"

MainMenu::MainMenu()
{
    float CentralWidth = WINDOW_WIGHT / 2;
    StartGameButton = std::make_unique<Button>("Start", sf::Vector2f(CentralWidth, 200.f));
    EditorButton = std::make_unique<Button>("Editor", sf::Vector2f(CentralWidth, 400.f));
    ExitButton = std::make_unique<Button>("Exit", sf::Vector2f(CentralWidth, 600.f));

    GAudioSubsystem->StartNewMusic("menu_music");
}

void MainMenu::Update()
{
    sf::Event event;
    while (GWindow->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            GWindow->close();
    }

    // Рассчет позиции мыши
    int xMousePos = (event.mouseButton.x);
    int yMousePos = (event.mouseButton.y);

    if (sf::Event::MouseButtonPressed and event.mouseButton.button == sf::Mouse::Left)
    {
        if (ExitButton->CheckWithCollisions(xMousePos, yMousePos))
        {
            GWindow->close();
        }
        if (StartGameButton->CheckWithCollisions(xMousePos, yMousePos))
        {
            GEngine->SwitchState<LevelSelector>();
            GAudioSubsystem->CreateNewSound("button_sound");
        }
        if (EditorButton->CheckWithCollisions(xMousePos, yMousePos))
        {
            GEngine->SwitchState<LevelEditorSelector>();
            GAudioSubsystem->CreateNewSound("button_sound");
        }
    }
}
