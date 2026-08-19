#include "LevelEditorSelector.h"

#include "Core/GameSubsystems/AudioSubsystem.h"
#include "GUI/Button.h"
#include "Core/DataFunctions.h"
#include "LevelEditor.h"
#include "MainMenu.h"
#include "GUI/Base/Image.h"

void ULevelEditorSelector::OnLevel1ButtonPressed()
{
    ChooseLevel(1);
}

void ULevelEditorSelector::OnLevel2ButtonPressed()
{
    ChooseLevel(2);
}

void ULevelEditorSelector::OnLevel3ButtonPressed()
{
    ChooseLevel(3);
}

ULevelEditorSelector::ULevelEditorSelector() : UGameState()
{
    CanvasImage = Construct<UImage>(nullptr);
    CanvasImage->SetTextureByName("background");

    float CentralWidth = WINDOW_WIGHT / 2;

    Level1Button = ConstructButton<UButton>(CanvasImage.get(), "level 1");
    Level1Button->onButtonPressed.Add(this, &ULevelEditorSelector::OnLevel1ButtonPressed);
    Level1Button->SetScreenPosition({ 0.0f, -192.0f });

    Level2Button = ConstructButton<UButton>(CanvasImage.get(), "level 2");
    Level2Button->onButtonPressed.Add(this, &ULevelEditorSelector::OnLevel2ButtonPressed);

    Level3Button = ConstructButton<UButton>(CanvasImage.get(), "level 3");
    Level3Button->onButtonPressed.Add(this, &ULevelEditorSelector::OnLevel3ButtonPressed);
    Level3Button->SetScreenPosition({ 0.0f, +192.0f });
}

void ULevelEditorSelector::ChooseLevel(int index)
{
    Engine->MarkToSwitchState<ULevelEditor>();
    ChangeDataParamater("CurrentLevel:", index);
}
