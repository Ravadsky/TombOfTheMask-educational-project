#pragma once
#include "UObject.h"
#include "SpriteComponent.h"
#include <memory>

enum class ActorType : int
{
    //row 1
    Player = 0,
    Wall = 1,
    CornerWall = 2,
    Spikes = 3,
    //row 2
    Archer = 4,
    Arrow = 5,
    Point = 6,
    Star = 7,
    //row 3
    PlayerStart = 8,
    PlayerStartBlock = 9,
    PlayerEnd = 10,
    PlayerEndBlock = 11,
    //row 4
    BackgroundWall = 12,
    EditorObject = 15,
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
    sf::Vector2f ActorLocation{ 0.f, 0.f };
    float ActorRotation{ 0.f };

    CollisionPreset Collision = CollisionPreset::Ignore;
    sf::FloatRect CollisionBox;

public:
     
    Actor(ActorType Type, sf::Vector2f position, float rotationAngle);

    void BeginPlay() override;
    virtual void Update() = 0;
    virtual void OnCollision(std::weak_ptr<Actor> OtherActor) = 0;

    bool CanTick();
    void MarkToKill();

    sf::Vector2f Getlocation();
    virtual sf::FloatRect GetCollisionBox();
    CollisionPreset GetCollisionPreset();

};

