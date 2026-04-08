#pragma once

#include "Config.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class InputSubsystem;
class ResourceSubsystem;
class RenderSubsystem;
class LevelSubsystem;
class PhysicsSubsystem;
class GarbageCollector;
class Engine;
class AudioSubsystem;

extern sf::RenderWindow *GWindow;
extern Engine *GEngine;
extern InputSubsystem *GInputSubsystem;
extern ResourceSubsystem *GResourceSubsystem;
extern RenderSubsystem *GRenderSubsystem;
extern LevelSubsystem *GLevelSubsystem;
extern PhysicsSubsystem *GPhysicsSubsystem;
extern GarbageCollector *GGarbageCollector;
extern AudioSubsystem *GAudioSubsystem;