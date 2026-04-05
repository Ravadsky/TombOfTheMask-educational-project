#pragma once
#include "Actor.h"
class PlayerStart : public Actor
{
  public:
    PlayerStart(sf::Vector2f position, float rotationAngle);

    void Update() override;
    void OnCollision(std::weak_ptr<Actor> OtherActor) override;
};
