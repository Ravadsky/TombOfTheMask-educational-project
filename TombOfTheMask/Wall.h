#pragma once
#include "Actor.h"
class Wall : public Actor
{
  private:
  public:
    Wall(sf::Vector2f position, float rotationAngle);

    void Update() override;
    void OnCollision(std::weak_ptr<Actor> OtherActor) override;
};
