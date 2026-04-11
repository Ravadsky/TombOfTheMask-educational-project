#pragma once
#include "Actor.h"

#include "Widget.h"

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

class Player : public Actor
{
  private:
    bool CanAction{true};

    sf::Vector2f PlayerDirection{0.f, 0.f};
    PlayerState State{PlayerState::Idle};

    int PointCount = 0;
    std::unique_ptr<Widget> PointCountWidget;

    int StarCount = 0;
    std::unique_ptr<Widget> StarCountWidget;

  public:
    Player(sf::Vector2f position, float rotationAngle);

    virtual void Update() override;
    virtual void BeginPlay() override;
    virtual void OnCollision(std::weak_ptr<Actor> OtherActor) override;

    void SetDirection(MoveDirection Direction);

    void UpdateLocation(sf::Vector2f position);

    sf::FloatRect GetCollisionBox();

    void AddPoint();
    int GetPointCount();

    void AddStar();
    int GetStarCount();

    void GetDamage();
};
