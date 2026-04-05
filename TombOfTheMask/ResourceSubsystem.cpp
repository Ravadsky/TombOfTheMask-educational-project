#include "ResourceSubsystem.h"
#include <assert.h>

ResourceSubsystem::ResourceSubsystem()
{
    assert(SpriteSheet.loadFromFile(RESOURCES_PATH + "Sprites.png"));
    assert(GameFont.loadFromFile(RESOURCES_PATH + "GUI/" + "Font.otf"));
}

void ResourceSubsystem::BeginPlay()
{
}

void ResourceSubsystem::Update()
{
}
