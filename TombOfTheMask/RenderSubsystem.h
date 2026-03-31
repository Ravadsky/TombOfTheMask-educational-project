#pragma once
#include "UObject.h"
#include <vector>
#include "Drawable.h"

class RenderSubsystem :
    public UObject
{
public:
    std::vector<Drawable*> ObjectsToDraw;

    RenderSubsystem();
    void BeginPlay() override;
    void Update() override;
};

