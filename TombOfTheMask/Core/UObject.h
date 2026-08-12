#pragma once
#include "CoreMinimal.h"

class UObject
{
private:
    bool bPendingToKill = false;

protected:
    bool bCanTick = false;

public:
    UObject();
    virtual ~UObject();

    virtual void BeginPlay() {};
    virtual void Update(float deltaTime) {};

    inline bool IsValid() const { return !bPendingToKill; }
    void MarkAsGarbage();

    inline bool CanTick() const { return bCanTick; }
};

template <typename T, typename K>
bool isClassOf(K* object)
{
    return dynamic_cast<T*>(object) != nullptr;
}

template <typename T, typename K>
T* CastTo(K* object)
{
    return dynamic_cast<T*>(object);
}