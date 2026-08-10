#include "LevelSelector.h"

#include "Core/GameSubsystems/AudioSubsystem.h"
#include "GUI/Button.h"
#include "Core/DataFunctions.h"
#include "GUI/LevelIcon.h"
#include "LevelInstance.h"
#include "MainMenu.h"

void ULevelSelector::OnLevel1ButtonPressed()
{
    ChooseLevel(1);
}

void ULevelSelector::OnLevel2ButtonPressed()
{
    ChooseLevel(2);
}

void ULevelSelector::OnLevel3ButtonPressed()
{
    ChooseLevel(3);
}

ULevelSelector::ULevelSelector()
{
    assert(LevelTexture.loadFromFile(RESOURCES_PATH + "GUI/Level.png"));
    assert(CompletedLevelTexture.loadFromFile(RESOURCES_PATH + "GUI/CompletedLevel.png"));
    assert(LockedLevelTexture.loadFromFile(RESOURCES_PATH + "GUI/LockedLevel.png"));

    GetAudioSubsystem()->StartNewMusic("menu_music");

    float width = WINDOW_WIGHT / 2 - 150.f;
    sf::Vector2f ButtonPos = { width, 150.f };
    sf::Vector2f ImageOffset = { 300.f, 0.f };

    Level1Button = std::make_unique<UButton>("Level 1");
    Level1Icon = std::make_unique<ULevelIcon>(ButtonPos + ImageOffset, *getLevelSprite(1), 1);
    Level1Button->onButtonPressed.Add(this, &ULevelSelector::OnLevel1ButtonPressed);

    ButtonPos += sf::Vector2f(0.f, 200.f);
    Level2Button = std::make_unique<UButton>("Level 2");
    Level2Icon = std::make_unique<ULevelIcon>(ButtonPos + ImageOffset, *getLevelSprite(2), 2);
    Level2Button->onButtonPressed.Add(this, &ULevelSelector::OnLevel2ButtonPressed);

    ButtonPos += sf::Vector2f(0.f, 200.f);
    Level3Button = std::make_unique<UButton>("Level 3");
    Level3Icon = std::make_unique<ULevelIcon>(ButtonPos + ImageOffset, *getLevelSprite(3), 3);
    Level3Button->onButtonPressed.Add(this, &ULevelSelector::OnLevel3ButtonPressed);
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
            Level1Button->TriggerIfCollision(xMousePos, yMousePos);
            Level2Button->TriggerIfCollision(xMousePos, yMousePos);
            Level3Button->TriggerIfCollision(xMousePos, yMousePos);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            Engine->MarkToSwitchState<UMainMenu>();
        }
    }
}

void ULevelSelector::ChooseLevel(int index)
{
    GetAudioSubsystem()->PlaySound("button_sound");

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
