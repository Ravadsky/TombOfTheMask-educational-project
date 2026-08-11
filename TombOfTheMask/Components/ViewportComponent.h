#pragma once
#include "ActorComponent.h"

class ULevelHUD;

class UViewportComponent : public UActorComponent
{
public:
    UViewportComponent(AActor* componentOwner);

    void AddStar();
    void AddPoint();
    inline int GetStarCount() const { return StarCount; }
    inline int GetPointCount() const { return PointCount; }

private:
    int PointCount = 0;
    int StarCount = 0;
    std::unique_ptr<ULevelHUD> LevelHUD;
};
