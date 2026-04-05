#include "CoreMinimal.h"
#include "GarbageCollector.h"
#include "InputSubsystem.h"
#include "PhysicsSubsystem.h"
#include "RenderSubsystem.h"
#include "ResourceSubsystem.h"

sf::RenderWindow *GWindow;

InputSubsystem *GInputSubsystem;
ResourceSubsystem *GResourceSubsystem;
RenderSubsystem *GRenderSubsystem;
LevelSubsystem *GLevelSubsystem;
PhysicsSubsystem *GPhysicsSubsystem;
GarbageCollector *GGarbageCollector;