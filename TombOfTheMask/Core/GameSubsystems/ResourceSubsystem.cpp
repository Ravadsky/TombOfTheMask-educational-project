#include "ResourceSubsystem.h"

#include "Actors/Player.h"
#include "Actors/Environment/Star.h"
#include "Actors/Environment/Point.h"
#include "Actors/Environment/Archer.h"
#include "Actors/Environment/Walls.h"
#include "Actors/Environment/EditorObject.h"
#include "Actors/Environment/PlayerEnd.h"
#include "Actors/Environment/PlayerStart.h"
#include "Actors/Environment/Spikes.h"

UResourceSubsystem::UResourceSubsystem()
{
    LoadGameFont("font.otf");
    LoadSpriteSheet("Sprites.png");

    LoadGUISprite("background");
    LoadGUISprite("selector");
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
    LoadSoundBuffer("hit");

    LoadAnimation("star_idle");
    LoadAnimation("star_pickup");
    LoadAnimation("spikes_idle");
    LoadAnimation("wall_hit_particle");

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

    RegisterByID<AWall>(0, "wall");
    RegisterByID<ACornerWall>(1, "corner_wall");
    RegisterByID<ABackgroundWall>(2, "background_wall");
    RegisterByID<ASpikes>(3, "spikes");
    RegisterByID<AArcher>(4, "archer");
    RegisterByID<APlayerStart>(5, "player_start");
    RegisterByID<APlayerStartBlock>(6, "player_start_block");
    RegisterByID<APlayerEnd>(7, "player_end");
    RegisterByID<APlayerEndBlock>(8, "player_end_block");
    RegisterByID<APoint>(9, "point");
    RegisterByID<AStar>(10, "star");

    // specific objects
    RegisterByID<APlayer>(51, "player", false);
    RegisterByID<AArrow>(52, "arrow", false);
    RegisterByID<AEditorObject>(99, "editor_object", false);
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

    SpriteSheet.loadFromFile(RESOURCES_PATH + filename);
}

void UResourceSubsystem::LoadGUISprite(const std::string& filename)
{
    StaticSprites[filename].loadFromFile(RESOURCES_PATH + "GUI/" + filename + ".png");
}

void UResourceSubsystem::LoadAnimation(const std::string& filename)
{
    StaticSprites[filename].loadFromFile(RESOURCES_PATH + "Animations/" + filename + ".png");
}

void UResourceSubsystem::LoadGameFont(const std::string& filename)
{
    GameFont.loadFromFile(RESOURCES_PATH + "GUI/" + filename);
}

void UResourceSubsystem::LoadSoundBuffer(const std::string& filename)
{
    sf::SoundBuffer newBuffer;
    newBuffer.loadFromFile(RESOURCES_PATH + "Audio/" + filename + ".wav");
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
