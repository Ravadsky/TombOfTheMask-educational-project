#include "TextBlock.h"

#include "Core/GameSubsystems/ResourceSubsystem.h"

UTextBlock::UTextBlock()
{
    TextContainer.setString("EMPTY");
    TextContainer.setFont(GetResourceSubsystem()->GetFont());
    TextContainer.setCharacterSize(SPRITE_GAME_SIZE);

    sf::FloatRect bounds = TextContainer.getLocalBounds();
    TextContainer.setOrigin(std::floor(bounds.left + bounds.width / 2.0f),
                            std::floor(bounds.top + bounds.height / 2.0f));
}

void UTextBlock::Render()
{
    Window->draw(TextContainer);
}

void UTextBlock::SetText(std::string newString)
{
    TextContainer.setString(newString);
}
