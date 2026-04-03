#pragma once
#include "Actor.h"
class EditorObject :
    public Actor
{
public:
    EditorObject(sf::Vector2f position, float rotationAngle);

    void Update() override;
    void OnCollision(std::weak_ptr<Actor> OtherActor) override;
};