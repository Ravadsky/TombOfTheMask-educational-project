#pragma once
#include "Drawable.h"
#include "UObject.h"
#include <vector>

class RenderSubsystem : public UObject
{
  private:
    sf::Vector2f *CameraPosition = nullptr;

  public:
    std::vector<Drawable *> ObjectsToDraw;

    RenderSubsystem();
    void Update() override;

    void SetCameraPosition(sf::Vector2f *position);

    void ClearObjectsToDraw();
};
