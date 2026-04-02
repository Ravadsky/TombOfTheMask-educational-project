#pragma once
#include "UObject.h"
#include "SpriteComponent.h"
#include <memory>

enum class ActorType : int
{
    Player = 0,
    Point = 1,
    Spikes = 2,
    Star = 3,
    Wall = 4,
    Archer = 5,
    Arrow = 6,
    BackgroundWall = 7,
    PlayerStart = 8,
    PlayerEnd = 9,
};

enum class CollisionPreset
{
    Ignore,
    Overlap,
    Block,
};

class Actor :
    public UObject, public std::enable_shared_from_this<Actor>
{
private:

protected:
    bool canTick = false;

    std::unique_ptr<SpriteComponent> ActorSprite;
    sf::Vector2f ActorLocation{ CAMERA_PIVOT };
    float ActorRotation{ 0.f };

    CollisionPreset Collision = CollisionPreset::Ignore;
    sf::FloatRect CollisionBox;

public:
     
    Actor(ActorType Type, sf::Vector2f position, float rotationAngle);
    virtual ~Actor() = default;
    void BeginPlay() override;
    virtual void Update() = 0;

    virtual void OnCollision(std::weak_ptr<Actor> OtherActor) = 0;
    bool CanTick();

    sf::Vector2f Getlocation();
    virtual sf::FloatRect GetCollisionBox();
    CollisionPreset GetCollisionPreset();

    void MarkToKill();
};

