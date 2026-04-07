#include "ResourceSubsystem.h"
#include <assert.h>

#include "Archer.h"
#include "Arrow.h"
#include "BackgroundWall.h"
#include "CornerWall.h"
#include "EditorObject.h"
#include "Player.h"
#include "PlayerEnd.h"
#include "PlayerEndBlock.h"
#include "PlayerStart.h"
#include "PlayerStartBlock.h"
#include "Point.h"
#include "Spikes.h"
#include "Star.h"
#include "Wall.h"

ResourceSubsystem::ResourceSubsystem()
{
    assert(SpriteSheet.loadFromFile(RESOURCES_PATH + "Sprites.png"));
    assert(GameFont.loadFromFile(RESOURCES_PATH + "GUI/" + "Font.otf"));

    AddBindActorID<Player>(0);
    AddBindActorID<Wall>(1);
    AddBindActorID<CornerWall>(2);
    AddBindActorID<Spikes>(3);
    AddBindActorID<Archer>(4);
    AddBindActorID<Arrow>(5);
    AddBindActorID<Point>(6);
    AddBindActorID<Star>(7);
    AddBindActorID<PlayerStart>(8);
    AddBindActorID<PlayerStartBlock>(9);
    AddBindActorID<PlayerEnd>(10);
    AddBindActorID<PlayerEndBlock>(11);
    AddBindActorID<BackgroundWall>(12);
    AddBindActorID<EditorObject>(15);
}