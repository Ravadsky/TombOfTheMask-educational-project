#include "UObject.h"
#include "GameSubsystems/GarbageCollector.h"

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
    if (bPendingToKill == false)
    {
        GetGarbageCollector()->AddObjectToKill(this);
        bPendingToKill = true;
    }
}
