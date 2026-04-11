#pragma once
#include "Config.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <assert.h>
#include <memory>

class Engine;
class InputSubsystem;
class ResourceSubsystem;
class RenderSubsystem;
class LevelSubsystem;
class PhysicsSubsystem;
class GarbageCollector;
class AudioSubsystem;

extern Engine *GEngine;
extern sf::RenderWindow *GWindow;
extern InputSubsystem *GInputSubsystem;
extern ResourceSubsystem *GResourceSubsystem;
extern RenderSubsystem *GRenderSubsystem;
extern LevelSubsystem *GLevelSubsystem;
extern PhysicsSubsystem *GPhysicsSubsystem;
extern GarbageCollector *GGarbageCollector;
extern AudioSubsystem *GAudioSubsystem;