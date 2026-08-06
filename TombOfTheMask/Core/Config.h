#pragma once
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include <string>

// Window
inline const std::string GAME_NAME = "Tomb ot the mask";

inline const int WINDOW_WIGHT = 1080;
inline const int WINDOW_HEIGHT = 720;
inline const sf::VideoMode GAME_VIDEOMODE(WINDOW_WIGHT, WINDOW_HEIGHT);
inline const sf::Vector2f CAMERA_PIVOT(WINDOW_WIGHT / 2, WINDOW_HEIGHT / 2);
inline const int MAX_FPS = 60;
inline const sf::Time TimeBeetweenStates = sf::milliseconds(200);
inline const sf::Color WindowColor = { 6, 6, 8, 255 };

// Resources
inline const std::string RESOURCES_PATH = "Resources/";
inline const int RAW_SPRITE_SIZE = 8;
inline const int SPRITE_GAME_SIZE = 64;
inline const sf::Vector2f PIXEL_RATIO = { SPRITE_GAME_SIZE / RAW_SPRITE_SIZE, SPRITE_GAME_SIZE / RAW_SPRITE_SIZE };
inline const int SpriteSheetSize = 4;

// Level
inline const int MAX_LEVEL_SIZE = 24;

// PLAYER
inline const int PLAYER_SPEED = 16;
