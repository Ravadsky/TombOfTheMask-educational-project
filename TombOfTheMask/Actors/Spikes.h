#pragma once
#include "Actor.h"

class Spikes : public Actor
{
  public:
    Spikes(sf::Vector2f position, float rotationAngle);

    virtual void OnCollision(std::weak_ptr<Actor> OtherActor) override;
};
