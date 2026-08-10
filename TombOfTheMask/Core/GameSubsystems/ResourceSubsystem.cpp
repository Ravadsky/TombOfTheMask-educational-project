#include "ResourceSubsystem.h"

UResourceSubsystem::UResourceSubsystem()
{
    LoadGameFont("Font.otf");
    LoadSpriteSheet("Sprites.png");

    // sprite sheet row 1
    LoadSpriteFromSpriteSheet("player", 1, 1);
    LoadSpriteFromSpriteSheet("wall", 1, 2);
    LoadSpriteFromSpriteSheet("corner_wall", 1, 3);
    LoadSpriteFromSpriteSheet("spikes", 1, 4);

    // sprite sheet row 2
    LoadSpriteFromSpriteSheet("archer", 2, 1);
    LoadSpriteFromSpriteSheet("arrow", 2, 2);
    LoadSpriteFromSpriteSheet("point", 2, 3);
    LoadSpriteFromSpriteSheet("star", 2, 4);

    // sprite sheet row 3
    LoadSpriteFromSpriteSheet("player_start", 3, 1);
    LoadSpriteFromSpriteSheet("player_start_block", 3, 2);
    LoadSpriteFromSpriteSheet("player_end", 3, 3);
    LoadSpriteFromSpriteSheet("player_end_block", 3, 4);

    // sprite sheet row 4
    LoadSpriteFromSpriteSheet("background_wall", 4, 1);
    LoadSpriteFromSpriteSheet("editor_object", 4, 2);
}

void UResourceSubsystem::LoadSpriteFromSpriteSheet(const std::string& spriteName, int row, int column)
{
    int left = (column - 1) * RAW_SPRITE_SIZE;
    int top = (row - 1) * RAW_SPRITE_SIZE;

    sf::IntRect rect(left, top, RAW_SPRITE_SIZE, RAW_SPRITE_SIZE);
    sf::Sprite sprite(SpriteSheet, rect);
    StaticSprites[spriteName] = sprite;
}

void UResourceSubsystem::LoadSpriteSheet(const std::string& filename)
{
    assert(SpriteSheet.loadFromFile(RESOURCES_PATH + filename));
}

void UResourceSubsystem::LoadGameFont(const std::string& filename)
{
    assert(GameFont.loadFromFile(RESOURCES_PATH + "GUI/" + filename));
}

sf::Sprite& UResourceSubsystem::GetSprite(const std::string& spriteName)
{
    return StaticSprites.at(spriteName);
}
const sf::Texture& UResourceSubsystem::GetTexture(const std::string& textureName)
{
    return *StaticSprites.at(textureName).getTexture();
}

sf::Font& UResourceSubsystem::GetFont()
{
    return GameFont;
}
