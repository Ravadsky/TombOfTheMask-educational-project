#pragma once
#include "Actor.h"
class CornerWall : public Actor
{
  private:
  public:
    CornerWall(sf::Vector2f position, float rotationAngle);

    void Update() override;
    void OnCollision(std::weak_ptr<Actor> OtherActor) override;
};
