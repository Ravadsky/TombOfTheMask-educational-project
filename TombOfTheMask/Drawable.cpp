#include "Drawable.h"
#include "RenderSubsystem.h"
#include <algorithm>

Drawable::Drawable()
{
    GRenderSubsystem->ObjectsToDraw.push_back(this);
}

Drawable::~Drawable()
{
    auto ItemIterator = std::find(GRenderSubsystem->ObjectsToDraw.begin(), GRenderSubsystem->ObjectsToDraw.end(), this);
    if (ItemIterator != GRenderSubsystem->ObjectsToDraw.end())
        GRenderSubsystem->ObjectsToDraw.erase(ItemIterator);
}
