#include "GarbageCollector.h"

UGarbageCollector::UGarbageCollector() : UGameSubsystem() {}

void UGarbageCollector::Update(float deltaTime)
{
    for (auto obj : ObjectsToKill)
    {
        if (obj != nullptr)
            delete obj;
    }
    ObjectsToKill.clear();
}

void UGarbageCollector::AddObjectToKill(UObject* object)
{
    ObjectsToKill.push_back(object);
}
