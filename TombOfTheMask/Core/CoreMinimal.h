#pragma once
#include "Config.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "UObject.h"
#include "Engine.h"
#include <assert.h>
#include <memory>
#include "Delegate.h"
#include "Math.h"

extern GEngine *Engine;
extern sf::RenderWindow *Window;

#define GetResourceSubsystem() Engine->GetResourceSubsystem()
#define GetRenderSubsystem() Engine->GetRenderSubsystem()
#define GetAudioSubsystem() Engine->GetAudioSubsystem()
#define GetGarbageCollector() Engine->GetGarbageCollector()