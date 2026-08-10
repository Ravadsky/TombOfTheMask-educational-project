#include "Button.h"
#include "Core/GameSubsystems/AudioSubsystem.h"

UButton::UButton(std::string text)
{
    assert(ButtonTexture.loadFromFile(RESOURCES_PATH + "GUI/Button.png"));
    ButtonText = std::make_unique<UTextBlock>(text);
}

void UButton::TriggerIfCollision(int xMousePos, int yMousePos)
{
    sf::Vector2f MousePos = { (float)xMousePos, (float)yMousePos };

    if (Sprite.getGlobalBounds().contains(MousePos))
    {
        onButtonPressed.Broadcast();
        GetAudioSubsystem()->PlaySound("button_sound");
    }
}

void UButton::Render() {}
