#include "GarbageCollector.h"
#include "Actor.h"
#include "LevelSubsystem.h"

GarbageCollector::GarbageCollector()
{
}

void GarbageCollector::BeginPlay()
{
}

void GarbageCollector::Update()
{

	auto& AllActors = GLevelSubsystem->ActorsOnLevel;

	for (auto actor : ActorsToKill)
	{
		if (auto _actor = actor.lock())
		{
			auto iter = std::find(AllActors.begin(), AllActors.end(), _actor);
			
			if (iter != AllActors.end()) AllActors.erase(iter);

		}

	}
	ActorsToKill.clear();
}
