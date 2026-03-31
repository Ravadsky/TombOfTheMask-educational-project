#pragma once
#include "UObject.h"
#include "SpriteComponent.h"

class Actor :
    public UObject
{
private:
    SpriteComponent* ActorSprite;
    sf::Vector2f ActorLocation;

public:

    Actor();
    ~Actor();
    void BeginPlay() override;
    void Update() override;
};

