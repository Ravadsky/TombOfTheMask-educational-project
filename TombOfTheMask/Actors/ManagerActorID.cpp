#include "ManagerActorID.h"
#include "World/World.h"

#include "Star.h"
#include "Point.h"
#include "Player.h"
#include "Environment/Archer.h"
#include "Environment/Arrow.h"
#include "Environment/BackgroundWall.h"
#include "Environment/CornerWall.h"
#include "Environment/Wall.h"
#include "Environment/EditorObject.h"
#include "Environment/PlayerEnd.h"
#include "Environment/PlayerEndBlock.h"
#include "Environment/PlayerStart.h"
#include "Environment/PlayerStartBlock.h"
#include "Environment/Spikes.h"

ManagerActorID::ManagerActorID(UWorld* InWorld)
{
    currentWorld = InWorld;

    RegisterByID<AEditorObject>(-1);
    RegisterByID<ABackgroundWall>(0);
    RegisterByID<AWall>(1);
    RegisterByID<ACornerWall>(2);
    RegisterByID<ASpikes>(3);
    RegisterByID<AArcher>(4);
    RegisterByID<AArrow>(5);
    RegisterByID<APlayer>(6);
    RegisterByID<APlayerStart>(7);
    RegisterByID<APlayerStartBlock>(8);
    RegisterByID<APlayerEnd>(9);
    RegisterByID<APlayerEndBlock>(10);
    RegisterByID<APoint>(11);
    RegisterByID<AStar>(12);
}
