#include "ResourceSubsystem.h"

UResourceSubsystem::UResourceSubsystem()
{
    LoadGameFont("font.otf");
    LoadSpriteSheet("Sprites.png");

    LoadGUISprite("background");
    LoadGUISprite("button");
    LoadGUISprite("completed_level_icon");
    LoadGUISprite("locked_level_icon");
    LoadGUISprite("level_icon");
    LoadGUISprite("music_off");
    LoadGUISprite("music_on");
    LoadGUISprite("sound_off");
    LoadGUISprite("sound_on");
    LoadGUISprite("star");
    LoadGUISprite("point");

    LoadSoundBuffer("archer");
    LoadSoundBuffer("button");
    LoadSoundBuffer("death");
    LoadSoundBuffer("star");
    LoadSoundBuffer("point");

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
    LoadSpriteFromSpriteSheet("editor_object", 4, 4);
}

void UResourceSubsystem::LoadSpriteFromSpriteSheet(const std::string& spriteName, int row, int column)
{
    int left = (column - 1) * RAW_SPRITE_SIZE;
    int top = (row - 1) * RAW_SPRITE_SIZE;
    sf::IntRect rect(left, top, RAW_SPRITE_SIZE, RAW_SPRITE_SIZE);

    StaticSprites[spriteName].loadFromImage(SpriteSheet.copyToImage(), rect);
}

void UResourceSubsystem::LoadSpriteSheet(const std::string& filename)
{

    assert(SpriteSheet.loadFromFile(RESOURCES_PATH + filename));
}

void UResourceSubsystem::LoadGUISprite(const std::string& filename)
{
    assert(StaticSprites[filename].loadFromFile(RESOURCES_PATH + "GUI/" + filename + ".png"));
}

void UResourceSubsystem::LoadGameFont(const std::string& filename)
{
    assert(GameFont.loadFromFile(RESOURCES_PATH + "GUI/" + filename));
}

void UResourceSubsystem::LoadSoundBuffer(const std::string& filename)
{
    sf::SoundBuffer newBuffer;
    assert(newBuffer.loadFromFile(RESOURCES_PATH + "Audio/" + filename + ".wav"));
    SoundBuffers[filename] = std::move(newBuffer);
}

const sf::Texture& UResourceSubsystem::GetTexture(const std::string& textureName)
{
    return StaticSprites.at(textureName);
}

const sf::SoundBuffer& UResourceSubsystem::GetSoundBuffer(const std::string& soundName)
{
    return SoundBuffers.at(soundName);
}

const sf::Font& UResourceSubsystem::GetFont()
{
    return GameFont;
}
