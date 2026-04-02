#pragma once
#include "Actor.h"

enum class MoveDirection
{
    Up,
    Down,
    Left,
    Right,
    NoDirection
};

enum class PlayerState
{
    Moving,
    Idle,
};

class Player :
    public Actor
{
private:
    sf::Vector2f PlayerDirection{ 0.f, 0.f };
    bool CanAction{ true };
    PlayerState State{ PlayerState::Idle };
    sf::Vector2f PrevLocation;

    int PointCount = 0;
    int StarCount = 0;    

public:
    Player(sf::Vector2f position, float rotationAngle);

    void Update() override;
    void BeginPlay() override;
    void OnCollision(std::weak_ptr<Actor> OtherActor) override;

    void SetDirection(MoveDirection Direction);

    void UpdateLocation(sf::Vector2f position);

    sf::FloatRect GetCollisionBox();

    void AddPoint();
    int GetPointCount();
    void AddStar();
    int GetStarCount();

};

