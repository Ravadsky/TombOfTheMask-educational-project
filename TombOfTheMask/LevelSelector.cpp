#include "LevelSelector.h"
#include "AudioSubsystem.h"
#include "Button.h"
#include "Engine.h"
#include "FunctionLibrary.h"
#include "LevelEditorSelector.h"
#include "LevelInstance.h"
#include "MainMenu.h"
#include "SpriteComponent.h"
#include "assert.h"
#include <fstream>
#include <vector>

LevelSelector::LevelSelector()
{
    assert(LevelTexture.loadFromFile(RESOURCES_PATH + "GUI/Level.png"));
    assert(CompletedLevelTexture.loadFromFile(RESOURCES_PATH + "GUI/CompletedLevel.png"));
    assert(LockedLevelTexture.loadFromFile(RESOURCES_PATH + "GUI/LockedLevel.png"));

    float CentralWidth = WINDOW_WIGHT / 2;
    sf::Vector2f ButtonPos = {CentralWidth, 150.f};
    sf::Vector2f ImageOffset = {300.f, 0.f};
    sf::Texture *TexturePtr;

    Level1 = std::make_unique<Button>("Level 1", ButtonPos);
    GetDataParameter("Level1:") ? TexturePtr = &CompletedLevelTexture : TexturePtr = &LevelTexture;
    Level1Sprite = std::make_unique<SpriteComponent>(*TexturePtr, ButtonPos + ImageOffset);
    Level1Sprite->SetDrawType(DrawType::Widget);

    ButtonPos += sf::Vector2f(0.f, 200.f);
    Level2 = std::make_unique<Button>("Level 2", sf::Vector2f(CentralWidth, 350.f));
    GetDataParameter("Level1:")
        ? (GetDataParameter("Level2:") ? TexturePtr = &CompletedLevelTexture : TexturePtr = &LevelTexture)
        : TexturePtr = &LockedLevelTexture;
    Level2Sprite = std::make_unique<SpriteComponent>(*TexturePtr, ButtonPos + ImageOffset);
    Level2Sprite->SetDrawType(DrawType::Widget);

    ButtonPos += sf::Vector2f(0.f, 200.f);
    Level3 = std::make_unique<Button>("Level 3", sf::Vector2f(CentralWidth, 550.f));
    GetDataParameter("Level2:")
        ? (GetDataParameter("Level3:") ? TexturePtr = &CompletedLevelTexture : TexturePtr = &LevelTexture)
        : TexturePtr = &LockedLevelTexture;
    Level3Sprite = std::make_unique<SpriteComponent>(*TexturePtr, ButtonPos + ImageOffset);
    Level3Sprite->SetDrawType(DrawType::Widget);
}

void LevelSelector::Update()
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

void LevelSelector::ChooseLevel(int index)
{
    GAudioSubsystem->CreateNewSound("button_sound");

    GEngine->SwitchState<LevelInstance>();
    ChangeDataParamater("CurrentLevel:", index);
}
