#pragma once
#include <string>
#include "SFML/Graphics.hpp"

//Window
const int WINDOW_WIGHT = 1080;
const int WINDOW_HEIGHT = 720;
const int MAX_FPS = 60;
const sf::Vector2f CAMERA_PIVOT = { WINDOW_WIGHT / 2, WINDOW_HEIGHT / 2 };


//Resources
const std::string RESOURCES_PATH = "Resources/";
const int RAW_SPRITE_SIZE = 8;
const int SPRITE_GAME_SIZE = 64;
const sf::Vector2f OBJECT_SIZE = { SPRITE_GAME_SIZE / RAW_SPRITE_SIZE, SPRITE_GAME_SIZE / RAW_SPRITE_SIZE };
const int SpriteSheetSize = 3;


//PLAYER
const int PLAYER_SPEED = 16;