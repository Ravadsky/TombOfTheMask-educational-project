#pragma once
#include "Actor.h"

class BackgroundWall : public Actor
{
  public:
    BackgroundWall(sf::Vector2f position, float rotationAngle);

    void Update() override;
    void OnCollision(std::weak_ptr<Actor> OtherActor) override;
};
