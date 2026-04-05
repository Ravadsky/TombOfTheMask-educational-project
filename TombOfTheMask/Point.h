#pragma once
#include "Actor.h"
class Point : public Actor
{
  private:
  public:
    Point(sf::Vector2f position, float rotationAngle);

    void Update() override;
    void OnCollision(std::weak_ptr<Actor> OtherActor) override;
};
