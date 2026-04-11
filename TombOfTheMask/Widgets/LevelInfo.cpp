#include "LevelInfo.h"

#include "DataFunctions.h"
#include "SpriteComponent.h"
#include "TextBox.h"

LevelInfo::LevelInfo(sf::Vector2f pos, sf::Texture &tex, int levelIndex)
{
    LevelSprite = std::make_unique<SpriteComponent>(tex, pos);
    LevelSprite->SetDrawType(DrawType::Widget);

    std::string key = "Level" + std::to_string(levelIndex);

    // Переменные для вывода текста
    int value, maxValue;
    std::string text;

    value = GetDataParameter(key + ".stars:");
    maxValue = GetDataParameter(key + ".maxstars:");
    text = std::to_string(value) + " / " + std::to_string(maxValue);
    StarCountText = std::make_unique<TextBox>(text, pos + sf::Vector2f(166.f, 0.f));

    value = GetDataParameter(key + ".points:");
    maxValue = GetDataParameter(key + ".maxpoints:");
    text = std::to_string(value) + " / " + std::to_string(maxValue);
    PointCountText = std::make_unique<TextBox>(text, pos + sf::Vector2f(166.f, 80.f));
}
