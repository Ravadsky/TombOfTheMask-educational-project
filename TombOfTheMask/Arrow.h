#pragma once
#include "Actor.h"
class Arrow : public Actor
{
  public:
    Arrow(sf::Vector2f position);
    ~Arrow();
    Arrow(sf::Vector2f position, float rotationAngle);

    void Update() override;
    void BeginPlay() override;
    void OnCollision(std::weak_ptr<Actor> OtherActor) override;
};
