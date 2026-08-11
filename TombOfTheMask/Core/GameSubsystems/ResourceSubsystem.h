#pragma once
#include "GameSubsystem.h"
#include <unordered_map>

class UResourceSubsystem : public UGameSubsystem
{
public:
    UResourceSubsystem();

    void LoadSpriteFromSpriteSheet(const std::string& spriteName, int row, int column);

    void LoadSpriteSheet(const std::string& filename);
    void LoadGUISprite(const std::string& filename);

    void LoadGameFont(const std::string& filename);
    void LoadSoundBuffer(const std::string& filename);

    const sf::Texture& GetTexture(const std::string& textureName);
    const sf::SoundBuffer& GetSoundBuffer(const std::string& soundName);
    const sf::Font& GetFont();

private:
    sf::Texture SpriteSheet;
    sf::Font GameFont;
    std::unordered_map<std::string, sf::Texture> StaticSprites;
    std::unordered_map<std::string, sf::SoundBuffer> SoundBuffers;
};
