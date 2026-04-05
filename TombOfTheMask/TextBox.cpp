#include "TextBox.h"
#include "ResourceSubsystem.h"

TextBox::TextBox(std::string text, sf::Vector2f pos)
{
    Type = DrawType::Widget;
    TextContainer.setString(text);
    TextContainer.setFont(GResourceSubsystem->GameFont);
    TextContainer.setPosition(pos);
    TextContainer.setCharacterSize(SPRITE_GAME_SIZE);

    sf::FloatRect bounds = TextContainer.getLocalBounds();
    TextContainer.setOrigin(std::floor(bounds.left + bounds.width / 2.0f),
                            std::floor(bounds.top + bounds.height / 2.0f));
}

void TextBox::BeginPlay()
{
}

void TextBox::Update()
{
}

void TextBox::Draw(sf::Vector2f position)
{
    GWindow->draw(TextContainer);
}

void TextBox::ChangeText(std::string newString)
{
    TextContainer.setString(newString);
}

