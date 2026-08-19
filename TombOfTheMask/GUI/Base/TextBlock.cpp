#include "TextBlock.h"

#include "Core/GameSubsystems/ResourceSubsystem.h"

UTextBlock::UTextBlock(UUserWidget* parent) : UUserWidget(parent)
{
    TextContainer.setFont(GetResourceSubsystem()->GetFont());
    TextContainer.setCharacterSize(SPRITE_GAME_SIZE);

    SetText("empty");
}

void UTextBlock::Render()
{
    TextContainer.setPosition(GetScreenPosition() + GetAlignmentOffset());
    Window->draw(TextContainer);
}

void UTextBlock::SetText(std::string newString)
{
    TextContainer.setString(newString);

    sf::FloatRect bounds = TextContainer.getLocalBounds();
    TextContainer.setOrigin(std::floor(bounds.left + bounds.width / 2.0f),
                            std::floor(bounds.top + bounds.height / 2.0f));
}
