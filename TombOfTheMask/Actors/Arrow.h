#pragma once
#include "Actor.h"

class Arrow : public Actor
{
  public:
    Arrow(sf::Vector2f position, float rotationAngle);

    virtual void Update() override;
    virtual void BeginPlay() override;
    virtual void OnCollision(std::weak_ptr<Actor> OtherActor) override;
};
