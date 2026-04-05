#pragma once
#include "Actor.h"
class PlayerEndBlock : public Actor
{
  private:
  public:
    PlayerEndBlock(sf::Vector2f position, float rotationAngle);

    void Update() override;
    void OnCollision(std::weak_ptr<Actor> OtherActor) override;
};
