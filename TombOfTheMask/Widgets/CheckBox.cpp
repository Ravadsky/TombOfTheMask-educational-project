#include "CheckBox.h"

#include "SpriteComponent.h"

CheckBox::CheckBox(std::string SpriteOn, std::string SpriteOff, sf::Vector2f pos)
{
    assert(TextureOn.loadFromFile(RESOURCES_PATH + "GUI/" + SpriteOn + ".png"));
    assert(TextureOff.loadFromFile(RESOURCES_PATH + "GUI/" + SpriteOff + ".png"));

    Sprite = std::make_unique<SpriteComponent>(TextureOn, pos);
    Sprite->SetDrawType(DrawType::Widget);
}
    
bool CheckBox::CheckWithCollisions(int xMousePos, int yMousePos)
{
    sf::Vector2f MousePos = {(float)xMousePos, (float)yMousePos};
    return Sprite->GetBounds().contains(MousePos);
}

void CheckBox::SetInitState(bool State)
{
    CurrentState = State;
    if (CurrentState)
    {
        Sprite->SetNewTexture(TextureOn);
        
    }
    else
    {
        Sprite->SetNewTexture(TextureOff);
    }
}

bool CheckBox::ChangeState()
{
    SetInitState(!CurrentState);
    return CurrentState;
}
