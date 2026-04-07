#include "Button.h"
#include "assert.h"

Button::Button(std::string text, sf::Vector2f pos)
{
    assert(ButtonTexture.loadFromFile(RESOURCES_PATH + "GUI/Button.png"));
    ButtonSprite = std::make_unique<SpriteComponent>(ButtonTexture, pos);
    ButtonText = std::make_unique<TextBox>(text, pos);

    ButtonSprite->SetDrawType(DrawType::Widget);
}

void Button::BeginPlay()
{
}

void Button::Update()
{
}

bool Button::CheckWithCollisions(int xMousePos, int yMousePos)
{
    sf::Vector2f MousePos = {(float)xMousePos, (float)yMousePos};
    return ButtonSprite->GetBounds().contains(MousePos);
}