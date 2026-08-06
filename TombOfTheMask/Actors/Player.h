#pragma once
#include "Actor.h"

#include "Widgets/Widget.h"

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

class APlayer : public AActor
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
    APlayer(sf::Vector2f position, float rotationAngle);

    virtual void Update(float deltaTime) override;
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
