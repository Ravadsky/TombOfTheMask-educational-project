#pragma once
#include "UObject.h"

#include "VectorFunctions.h"

class Drawable;

class RenderSubsystem : public UObject
{
  private:
    sf::Vector2f *CameraPosition = nullptr;

  public:
    std::vector<Drawable *> ObjectsToDraw;

    RenderSubsystem();
    virtual void Update() override;

    void SetCameraPosition(sf::Vector2f *position);

    void ClearObjectsToDraw();
};
