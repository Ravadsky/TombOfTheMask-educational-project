#include "LevelSelector.h"

#include "Core/GameSubsystems/AudioSubsystem.h"
#include "GUI/Button.h"
#include "Core/DataFunctions.h"
#include "GUI/LevelIcon.h"
#include "LevelInstance.h"
#include "MainMenu.h"

ULevelSelector::ULevelSelector()
{
    assert(LevelTexture.loadFromFile(RESOURCES_PATH + "GUI/Level.png"));
    assert(CompletedLevelTexture.loadFromFile(RESOURCES_PATH + "GUI/CompletedLevel.png"));
    assert(LockedLevelTexture.loadFromFile(RESOURCES_PATH + "GUI/LockedLevel.png"));

    float width = WINDOW_WIGHT / 2 - 150.f;
    sf::Vector2f ButtonPos = { width, 150.f };
    sf::Vector2f ImageOffset = { 300.f, 0.f };

    Level1 = std::make_unique<Button>("Level 1", ButtonPos);
    Level1Sprite = std::make_unique<LevelInfo>(ButtonPos + ImageOffset, *getLevelSprite(1), 1);

    ButtonPos += sf::Vector2f(0.f, 200.f);
    Level2 = std::make_unique<Button>("Level 2", sf::Vector2f(width, 350.f));
    Level2Sprite = std::make_unique<LevelInfo>(ButtonPos + ImageOffset, *getLevelSprite(2), 2);

    ButtonPos += sf::Vector2f(0.f, 200.f);
    Level3 = std::make_unique<Button>("Level 3", sf::Vector2f(width, 550.f));
    Level3Sprite = std::make_unique<LevelInfo>(ButtonPos + ImageOffset, *getLevelSprite(3), 3);

    GetAudioSubsystem()->StartNewMusic("menu_music");
}

void ULevelSelector::Update(float deltaTime)
{
    sf::Event event;
    // Рассчет позиции мыши
    int xMousePos = sf::Mouse::getPosition(*Window).x;
    int yMousePos = sf::Mouse::getPosition(*Window).y;

    while (Window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            Window->close();

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
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
            Engine->MarkToSwitchState<MainMenu>();
        }
    }
}

void ULevelSelector::ChooseLevel(int index)
{
    GetAudioSubsystem()->CreateNewSound("button_sound");

    Engine->MarkToSwitchState<LevelInstance>();
    ChangeDataParamater("CurrentLevel:", index);
}

sf::Texture* ULevelSelector::getLevelSprite(int CurrentLevel)
{
    int LastLevel = CurrentLevel - 1;

    if (LastLevel == 0)
        return GetDataParameter("Level1:") ? &CompletedLevelTexture : &LevelTexture;

    if (GetDataParameter("Level" + std::to_string(LastLevel) + ":") == 0)
        return &LockedLevelTexture;
    else
        return GetDataParameter("Level" + std::to_string(CurrentLevel) + ":") ? &CompletedLevelTexture : &LevelTexture;
}
