#pragma once
#include "UObject.h"
#include "SpriteComponent.h"

enum class ActorType : int
{
    Player = 0,
    Point = 1,
    Spikes = 2,
    Star = 3,
    Wall = 4,
    ProjWall = 5,
    Arrow = 6,
    BackgroundWall = 7,
    Exit = 8,
};

enum class CollisionPreset
{
    Ignore,
    Overlap,
    Block,
};

class Actor :
    public UObject
{
private:

protected:
    bool canTick = false;

    SpriteComponent* ActorSprite;
    sf::Vector2f ActorLocation{ CAMERA_PIVOT };

    CollisionPreset Collision = CollisionPreset::Ignore;
    sf::FloatRect CollisionBox;

public:

    Actor(ActorType Type, sf::Vector2f position);
    ~Actor();
    void BeginPlay() override;
    virtual void Update() = 0;

    virtual void OnCollision(Actor* OtherActor) = 0;
    bool CanTick();

    sf::Vector2f Getlocation();
    sf::FloatRect GetCollisionBox();
};

