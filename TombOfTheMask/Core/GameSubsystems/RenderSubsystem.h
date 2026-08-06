#pragma once
#include "GameSubsystem.h"

class Drawable;

class URenderSubsystem : public UGameSubsystem
{
  private:
    sf::Vector2f *CameraPosition = nullptr;

  public:
    std::vector<Drawable *> ObjectsToDraw;

    URenderSubsystem();
    virtual void Update(float deltaTime) override;

    void SetCameraPosition(sf::Vector2f *position);

    void ClearObjectsToDraw();
};
