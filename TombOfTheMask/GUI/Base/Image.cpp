#include "Image.h"
#include "Core/GameSubsystems/ResourceSubsystem.h"

UImage::UImage(UUserWidget* parent) : UUserWidget(parent)
{
    Sprite.setScale(PIXEL_RATIO);

}

void UImage::Render()
{
    Sprite.setPosition(GetScreenPosition() + GetAlignmentOffset());
    Window->draw(Sprite);
}

void UImage::SetTextureByName(std::string newString)
{
    auto& newTexture = GetResourceSubsystem()->GetTexture(newString);
    Sprite.setTexture(newTexture);
    Sprite.setTextureRect(sf::IntRect(0, 0, newTexture.getSize().x, newTexture.getSize().y));

    sf::FloatRect bounds = Sprite.getLocalBounds();
    Sprite.setOrigin(std::floor(bounds.left + bounds.width / 2.0f), std::floor(bounds.top + bounds.height / 2.0f));
}

bool UImage::ContainsMouse(sf::Vector2f mouseCoords)
{
    return Sprite.getGlobalBounds().contains(mouseCoords);
}