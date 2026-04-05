#pragma once
#include "Drawable.h"
#include "UObject.h"
#include <vector>

class RenderSubsystem : public UObject
{
  private:
    sf::Vector2f *CameraPosition;

  public:
    std::vector<Drawable *> ObjectsToDraw;

    RenderSubsystem();
    void BeginPlay() override;
    void Update() override;

    void SetCameraPosition(sf::Vector2f *position);
};
