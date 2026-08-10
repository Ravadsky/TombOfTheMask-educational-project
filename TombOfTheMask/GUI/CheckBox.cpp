#include "CheckBox.h"
#include "Core/GameSubsystems/AudioSubsystem.h"

UCheckBox::UCheckBox(std::string SpriteOn, std::string SpriteOff)
{
    assert(TextureOn.loadFromFile(RESOURCES_PATH + "GUI/" + SpriteOn + ".png"));
    assert(TextureOff.loadFromFile(RESOURCES_PATH + "GUI/" + SpriteOff + ".png"));

    Sprite.setTexture(TextureOn);
}

void UCheckBox::TriggerIfCollision(int xMousePos, int yMousePos)
{
    sf::Vector2f MousePos = { (float)xMousePos, (float)yMousePos };
    if (Sprite.getGlobalBounds().contains(MousePos))
    {
        onCheckBoxPressed.Broadcast();
        GetAudioSubsystem()->PlaySound("button_sound");
    }
}

void UCheckBox::SetInitState(bool State)
{
    CurrentState = State;

    auto& texture = CurrentState ? TextureOn : TextureOff;
    Sprite.setTexture(texture);
}

bool UCheckBox::ChangeState()
{
    SetInitState(!CurrentState);
    return CurrentState;
}

void UCheckBox::Render()
{
    Window->draw(Sprite);
}