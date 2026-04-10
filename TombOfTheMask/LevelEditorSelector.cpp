#include "LevelEditorSelector.h"
#include "AudioSubsystem.h"
#include "Button.h"
#include "Engine.h"
#include "FunctionLibrary.h"
#include "LevelEditor.h"
#include "MainMenu.h"

LevelEditorSelector::LevelEditorSelector()
{
    float CentralWidth = WINDOW_WIGHT / 2;
    Level1 = std::make_unique<Button>("Level 1", sf::Vector2f(CentralWidth, 200.f));
    Level2 = std::make_unique<Button>("Level 2", sf::Vector2f(CentralWidth, 350.f));
    Level3 = std::make_unique<Button>("Level 3", sf::Vector2f(CentralWidth, 500.f));
}

void LevelEditorSelector::Update()
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
        if (Level1->CheckWithCollisions(xMousePos, yMousePos))
        {
            ChooseLevel(1);
        }
        if (Level2->CheckWithCollisions(xMousePos, yMousePos))
        {
            // Если прошлый уровень пройден
            if (GetDataParameter("Level1:"))
            {
                ChooseLevel(2);
            }
        }
        if (Level3->CheckWithCollisions(xMousePos, yMousePos))
        {
            // Если прошлый уровень пройден
            if (GetDataParameter("Level2:"))
            {
                ChooseLevel(3);
            }
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        GEngine->SwitchState<MainMenu>();
    }
}

void LevelEditorSelector::ChooseLevel(int index)
{
    GAudioSubsystem->CreateNewSound("button_sound");

    GEngine->SwitchState<LevelEditor>();
    ChangeDataParamater("CurrentLevel:", index);
}
