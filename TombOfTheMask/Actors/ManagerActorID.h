#pragma once
#include <unordered_map>
#include <functional>
#include "Actor.h"

class UWorld;

class ManagerActorID
{
private:
    std::unordered_map<int, std::function<AActor*()>> actorsID;
    UWorld* currentWorld;

public:
    ManagerActorID(UWorld* InWorld);

    template <typename T>
    void RegisterByID(int id)
    {
        actorsID[id] = [this]() -> AActor* { return new T(currentWorld); };
    }
    inline AActor* Create(int id) const
    {
        auto it = actorsID.find(id);
        return (it != actorsID.end()) ? it->second() : nullptr;
    }
};
