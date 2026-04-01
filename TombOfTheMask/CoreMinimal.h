#pragma once

#include "Config.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class InputSubsystem;
class ResourceSubsystem;
class RenderSubsystem;
class LevelSubsystem;
class PhysicsSubsystem;

extern sf::RenderWindow* GWindow;
extern InputSubsystem* GInputSubsystem;
extern ResourceSubsystem* GResourceSubsystem;
extern RenderSubsystem* GRenderSubsystem;
extern LevelSubsystem* GLevelSubsystem;
extern PhysicsSubsystem* GPhysicsSubsystem;