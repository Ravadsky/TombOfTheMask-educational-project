#pragma once
#include "Actor.h"
class Archer :
    public Actor
{
private:
    float timer = 0.f;
    sf::Vector2f CellPosition;

public:
    Archer(sf::Vector2f position);
    Archer(sf::Vector2f position, float rotationAngle);

    void Update() override;
    void OnCollision(std::weak_ptr<Actor> OtherActor) override;
};

