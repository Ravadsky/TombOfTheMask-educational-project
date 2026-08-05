#pragma once
#include "Actor.h"

class Archer : public Actor
{
  private:
    float timer = 0.f;
    sf::Vector2f CellPosition;

  public:
    Archer(sf::Vector2f position, float rotationAngle);

    virtual void Update() override;
};
