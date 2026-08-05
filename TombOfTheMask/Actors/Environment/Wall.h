#pragma once
#include "Actor.h"

class Wall : public Actor
{
  public:
    Wall(sf::Vector2f position, float rotationAngle);
};
