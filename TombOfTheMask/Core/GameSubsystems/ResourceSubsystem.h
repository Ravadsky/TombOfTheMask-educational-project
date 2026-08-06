#pragma once
#include "GameSubsystem.h"
#include <unordered_map>

class UResourceSubsystem : public UGameSubsystem
{
public:
    UResourceSubsystem();

    void LoadSpriteFromSpriteSheet(const std::string& spriteName, int row, int column);

    void LoadSpriteSheet(const std::string& filename);
    void LoadGameFont(const std::string& filename);

    sf::Sprite& GetSprite(const std::string& spriteName);

private:
    sf::Texture SpriteSheet;
    sf::Font GameFont;
    std::unordered_map<std::string, sf::Sprite> StaticSprites;
};
