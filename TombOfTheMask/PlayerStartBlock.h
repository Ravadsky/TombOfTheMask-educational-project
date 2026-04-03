#pragma once
#include "Actor.h"
class PlayerStartBlock :
    public Actor
{
private:

public:
    PlayerStartBlock(sf::Vector2f position, float rotationAngle);

    void Update() override;
    void OnCollision(std::weak_ptr<Actor> OtherActor) override;
};