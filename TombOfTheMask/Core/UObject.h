#pragma once
#include "CoreMinimal.h"

class UObject
{
protected:
    bool bCanTick = false;

public:
    UObject();
    virtual ~UObject();

    virtual void BeginPlay() {};
    virtual void Update(float deltaTime) {};

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