#pragma once
#include "Actor.h"

#include "GUI/UserWidget.h"

class UInputComponent;
class UMovementComponent;
class UCameraComponent;

enum class PlayerState
{
    Moving,
    Idle,
};

class APlayer : public AActor
{
private:
    bool CanAction{ true };

    sf::Vector2f PlayerDirection{ 0.f, 0.f };
    PlayerState State{ PlayerState::Idle };

    int PointCount = 0;
    std::unique_ptr<Widget> PointCountWidget;

    int StarCount = 0;
    std::unique_ptr<Widget> StarCountWidget;

    UInputComponent* InputComponent;
    UMovementComponent* MovementComponent;
    UCameraComponent* CameraComponent;

public:
    APlayer(UWorld* InWorld);

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
