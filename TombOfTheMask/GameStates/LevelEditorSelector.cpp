#include "LevelEditorSelector.h"

#include "AudioSubsystem.h"
#include "Button.h"
#include "DataFunctions.h"
#include "Engine.h"
#include "LevelEditor.h"
#include "MainMenu.h"

LevelEditorSelector::LevelEditorSelector()
{
    assert(BackgroundTexture.loadFromFile(RESOURCES_PATH + "GUI/Background.png"));
    Background = std::make_unique<SpriteComponent>(BackgroundTexture, CAMERA_PIVOT);
    Background->SetDrawType(DrawType::Widget);

    float CentralWidth = WINDOW_WIGHT / 2;
    Level1 = std::make_unique<Button>("Level 1", sf::Vector2f(CentralWidth, 200.f));
    Level2 = std::make_unique<Button>("Level 2", sf::Vector2f(CentralWidth, 400.f));
    Level3 = std::make_unique<Button>("Level 3", sf::Vector2f(CentralWidth, 600.f));

    GAudioSubsystem->StartNewMusic("menu_music");
}

void LevelEditorSelector::Update()
{
    sf::Event event;
    // Рассчет позиции мыши
    int xMousePos = sf::Mouse::getPosition(*GWindow).x;
    int yMousePos = sf::Mouse::getPosition(*GWindow).y;

    while (GWindow->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            GWindow->close();

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (Level1->CheckWithCollisions(xMousePos, yMousePos))
            {
                ChooseLevel(1);
            }
            if (Level2->CheckWithCollisions(xMousePos, yMousePos))
            {
                ChooseLevel(2);
            }
            if (Level3->CheckWithCollisions(xMousePos, yMousePos))
            {
                ChooseLevel(3);
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            GEngine->SwitchState<MainMenu>();
        }
    }
}

void LevelEditorSelector::ChooseLevel(int index)
{
    GAudioSubsystem->CreateNewSound("button_sound");

    GEngine->SwitchState<LevelEditor>();
    ChangeDataParamater("CurrentLevel:", index);
}
