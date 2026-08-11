#pragma once
#include "ActorComponent.h"

class UCameraComponent : public UActorComponent
{
public:
    UCameraComponent(AActor* componentOwner);
    virtual ~UCameraComponent();

    sf::Vector2f GetCameraPosition();

protected:
    sf::Vector2f MinCameraPos;
    sf::Vector2f MaxCameraPos;
};
