#pragma once
#include "Actor.h"
class Spikes :
    public Actor
{
private:

public:
    Spikes(sf::Vector2f position, float rotationAngle);

    void Update() override;
    void OnCollision(std::weak_ptr<Actor> OtherActor) override;
};

