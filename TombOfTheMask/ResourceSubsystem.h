#pragma once
#include "UObject.h"

class ResourceSubsystem : public UObject
{
  public:
    sf::Texture SpriteSheet;
    sf::Font GameFont;

    ResourceSubsystem();
    void BeginPlay() override;
    void Update() override;
};
