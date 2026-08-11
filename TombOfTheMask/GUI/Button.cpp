#include "Button.h"
#include "Core/GameSubsystems/AudioSubsystem.h"
#include "Base/TextBlock.h"
#include "Base/Image.h"

UButton::UButton(UUserWidget* parent) : UUserWidget(parent)
{
    ButtonImage = std::make_unique<UImage>(this);
    ButtonImage->SetTextureByName("button");

    ButtonText = std::make_unique<UTextBlock>(this);
}

void UButton::TriggerIfCollision(int xMousePos, int yMousePos)
{
    if (ButtonImage->ContainsMouse({ (float)xMousePos, (float)yMousePos }))
    {
        onButtonPressed.Broadcast();
        GetAudioSubsystem()->PlaySound("button");
    }
}

void UButton::SetButtonText(std::string newText)
{
    ButtonText->SetText(newText);
}

void UButton::Render() {}
