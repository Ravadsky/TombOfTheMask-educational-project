#pragma once
#include "Actor.h"

class PlayerEnd : public Actor
{
  public:
    PlayerEnd(sf::Vector2f position, float rotationAngle);

    virtual void OnCollision(std::weak_ptr<Actor> OtherActor) override;
};
