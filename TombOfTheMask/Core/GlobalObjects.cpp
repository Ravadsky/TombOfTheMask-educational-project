#include "CoreMinimal.h"
#include "Engine.h"
#include "Subsystems/GameSubsystems/AudioSubsystem.h"
#include "Subsystems/GameSubsystems/GarbageCollector.h"
#include "Subsystems/WorldSubsystems/InputSubsystem.h"
#include "Subsystems/WorldSubsystems/PhysicsSubsystem.h"
#include "Subsystems/GameSubsystems/RenderSubsystem.h"
#include "Subsystems/GameSubsystems/ResourceSubsystem.h"

sf::RenderWindow *GWindow;

InputSubsystem *GInputSubsystem;
ResourceSubsystem *GResourceSubsystem;
RenderSubsystem *GRenderSubsystem;
LevelSubsystem *GLevelSubsystem;
PhysicsSubsystem *GPhysicsSubsystem;
GarbageCollector *GGarbageCollector;
GEngine *GetEngine;
AudioSubsystem *GAudioSubsystem;