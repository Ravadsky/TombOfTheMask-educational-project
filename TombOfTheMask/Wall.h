#pragma once
#include "Actor.h"
class Wall :
    public Actor
{
private:

public:
    Wall(sf::Vector2f position);

    void Update() override;
    void OnCollision(Actor* OtherActor) override;
};

