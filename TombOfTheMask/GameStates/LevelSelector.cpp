#include "LevelSelector.h"

#include "Core/DataFunctions.h"
#include "LevelInstance.h"
#include "MainMenu.h"

#include "GUI/Button.h"
#include "GUI/LevelIcon.h"
#include "GUI/Base/Image.h"

void ULevelSelector::OnLevel1ButtonPressed()
{
    ChooseLevel(1);
}

void ULevelSelector::OnLevel2ButtonPressed()
{
    if (GetDataParameter("Level1:"))
        ChooseLevel(2);
}

void ULevelSelector::OnLevel3ButtonPressed()
{
    if (GetDataParameter("Level2:"))
        ChooseLevel(3);
}

ULevelSelector::ULevelSelector() : UGameState()
{
    float width = WINDOW_WIGHT / 2 - 150.f;
    sf::Vector2f ButtonPos = { width, 150.f };
    sf::Vector2f ImageOffset = { 300.f, 0.f };

    CanvasImage = Construct<UImage>(nullptr);
    CanvasImage->SetTextureByName("background");

    Level1Button = ConstructButton<UButton>(CanvasImage.get(), "level 1");
    Level1Button->onButtonPressed.Add(this, &ULevelSelector::OnLevel1ButtonPressed);
    Level1Button->SetScreenPosition({ 0.0f, -192.0f });

    Level1Icon = Construct<ULevelIcon>(CanvasImage.get());
    Level1Icon->SetLevelInfo(1);
    Level1Icon->SetScreenPosition({ -340.0f, -192.0f });

    //

    Level2Button = ConstructButton<UButton>(CanvasImage.get(), "level 2");
    Level2Button->onButtonPressed.Add(this, &ULevelSelector::OnLevel2ButtonPressed);

    Level2Icon = Construct<ULevelIcon>(CanvasImage.get());
    Level2Icon->SetLevelInfo(2);
    Level2Icon->SetScreenPosition({ -340.0f, 0.0f });

    //

    Level3Button = ConstructButton<UButton>(CanvasImage.get(), "level 3");
    Level3Button->onButtonPressed.Add(this, &ULevelSelector::OnLevel3ButtonPressed);
    Level3Button->SetScreenPosition({ 0.0f, +192.0f });

    Level3Icon = Construct<ULevelIcon>(CanvasImage.get());
    Level3Icon->SetLevelInfo(3);
    Level3Icon->SetScreenPosition({ -340.0f, +192.0f });
}

void ULevelSelector::ChooseLevel(int index)
{
    Engine->MarkToSwitchState<ULevelInstance>();
    ChangeDataParamater("CurrentLevel:", index);
}