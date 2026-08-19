#include "CheckBox.h"
#include "Core/GameSubsystems/AudioSubsystem.h"
#include "Base/TextBlock.h"
#include "Base/Image.h"

UCheckBox::UCheckBox(UUserWidget* parent) : UButton(parent)
{
    ButtonImage = std::make_unique<UImage>(this);
    ButtonImage->SetAlignment(EHorizontalAlignment::Left, EVerticalAlignment::Top);

    ButtonText = std::make_unique<UTextBlock>(this);
    ButtonImage->SetAlignment(EHorizontalAlignment::Left, EVerticalAlignment::Top);
}

void UCheckBox::SetInitState(bool State)
{
    CurrentState = State;

    auto& textureName = CurrentState ? TextureOn : TextureOff;
    ButtonImage->SetTextureByName(textureName);
}

bool UCheckBox::ChangeState()
{
    SetInitState(!CurrentState);
    return CurrentState;
}

void UCheckBox::SetTextureNames(std::string textureOn, std::string textureOff)
{
    TextureOn = textureOn;
    TextureOff = textureOff;
}
