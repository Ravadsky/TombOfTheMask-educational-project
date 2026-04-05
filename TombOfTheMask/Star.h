#pragma once
#include "Actor.h"
class Star : public Actor
{
  public:
    Star(sf::Vector2f position, float rotationAngle);

    void Update() override;
    void OnCollision(std::weak_ptr<Actor> OtherActor) override;
};
