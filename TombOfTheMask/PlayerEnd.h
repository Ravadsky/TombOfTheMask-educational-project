#pragma once
#include "Actor.h"
class PlayerEnd : public Actor
{
  private:
  public:
    PlayerEnd(sf::Vector2f position, float rotationAngle);

    void Update() override;
    void OnCollision(std::weak_ptr<Actor> OtherActor) override;
};
