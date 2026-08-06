#include "UObject.h"
#include "Subsystems/GameSubsystems/GarbageCollector.h"

UObject::UObject()
{
    Engine->RegisterObject(this);
}

UObject::~UObject()
{
    Engine->UnregisterObject(this);
}

void UObject::MarkAsGarbage()
{
    GetGarbageCollector()->AddObjectToKill(this);
}
