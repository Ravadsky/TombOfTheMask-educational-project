#include "Actor.h"
#include "LevelSubsystem.h"
Actor::Actor()
{
	GLevelSubsystem->ActorsOnLevel.push_back(this);

	ActorSprite = new SpriteComponent(0);
}

Actor::~Actor()
{
	auto ItemIterator = std::find(GLevelSubsystem->ActorsOnLevel.begin(), GLevelSubsystem->ActorsOnLevel.end(), this);
	GLevelSubsystem->ActorsOnLevel.erase(ItemIterator);
}

void Actor::BeginPlay()
{
}

void Actor::Update()
{

	ActorSprite->SetPosition({128.f, 128.f});
}
