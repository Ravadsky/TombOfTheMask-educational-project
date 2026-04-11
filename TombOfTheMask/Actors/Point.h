#pragma once
#include "Actor.h"

class Point : public Actor
{
  public:
    Point(sf::Vector2f position, float rotationAngle);

    virtual void OnCollision(std::weak_ptr<Actor> OtherActor) override;
};
