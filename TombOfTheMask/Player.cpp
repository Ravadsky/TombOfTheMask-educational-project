#include "Player.h"
#include "AudioSubsystem.h"
#include "FunctionLibrary.h"
#include "LevelSubsystem.h"
#include "PhysicsSubsystem.h"
#include "Point.h"
#include "RenderSubsystem.h"
#include "Widget.h"
#include "Arrow.h"
#include "Engine.h"
#include "LevelInstance.h"

Player::Player(sf::Vector2f position, float rotationAngle) : Actor(ActorType::Player, position, rotationAngle)
{
    canTick = true;
    Collision = CollisionPreset::Block;

    CollisionBox = {position.x - SPRITE_GAME_SIZE / 4, position.y - SPRITE_GAME_SIZE / 4, SPRITE_GAME_SIZE / 2,
                    SPRITE_GAME_SIZE / 2};

    ActorSprite->SetDrawType(DrawType::Dynamic);
}

void Player::Update()
{
    UpdateLocation(PlayerDirection * (float)PLAYER_SPEED);
}

void Player::BeginPlay()
{
    GLevelSubsystem->CurrentPlayer = std::static_pointer_cast<Player>(shared_from_this());
    GRenderSubsystem->SetCameraPosition(&ActorLocation);
    if (GPhysicsSubsystem)
        GPhysicsSubsystem->TriggerActors.emplace_back(shared_from_this());

    std::string PointText = std::to_string(PointCount) + " / " + std::to_string(GLevelSubsystem->PointCountOnLevel);
    PointCountWidget = std::make_unique<Widget>(sf::Vector2f(64, 64), "Point", PointText);

    std::string StarText = std::to_string(StarCount) + " / " + std::to_string(GLevelSubsystem->StarCountOnLevel);
    StarCountWidget = std::make_unique<Widget>(sf::Vector2f(64, 128), "Star", StarText);
}

void Player::OnCollision(std::weak_ptr<Actor> OtherActor)
{
    if (auto other = OtherActor.lock())
    {
        if (other.get() != this)
        {
            auto preset = other->GetCollisionPreset();
            switch (preset)
            {
            case CollisionPreset::Block:
                UpdateLocation({-PlayerDirection.x * PLAYER_SPEED, -PlayerDirection.y * PLAYER_SPEED});
                PlayerDirection = {0.f, 0.f};
                if (isClassOf<Arrow>(other))
                    CanAction = false;
                else
                    CanAction = true;
                break;
            }
        }
    }
}

void Player::SetDirection(MoveDirection Direction)
{
    if (CanAction)
        switch (Direction)
        {
        case MoveDirection::Up:
            PlayerDirection = {0.f, -1.f};
            CanAction = false;
            ActorSprite->SetRotation(90.f);
            ActorSprite->Flip(true);
            break;
        case MoveDirection::Down:
            PlayerDirection = {0.f, 1.f};
            CanAction = false;
            ActorSprite->SetRotation(90.f);
            ActorSprite->Flip(false);
            break;
        case MoveDirection::Left:
            PlayerDirection = {-1.f, 0.f};
            CanAction = false;
            ActorSprite->SetRotation(0.f);
            ActorSprite->Flip(true);
            break;
        case MoveDirection::Right:
            PlayerDirection = {1.f, 0.f};
            CanAction = false;
            ActorSprite->SetRotation(0.f);
            ActorSprite->Flip(false);

            break;
        case MoveDirection::NoDirection:
            PlayerDirection = {0.f, 0.f};
        }
}

void Player::UpdateLocation(sf::Vector2f position)
{
    ActorLocation += position;
    CollisionBox = {ActorLocation.x - SPRITE_GAME_SIZE / 4, ActorLocation.y - SPRITE_GAME_SIZE / 4,
                    SPRITE_GAME_SIZE / 2, SPRITE_GAME_SIZE / 2};
    ActorSprite->SetPosition(ActorLocation);
}

sf::FloatRect Player::GetCollisionBox()
{

    float TempWidth = SPRITE_GAME_SIZE / 2;
    float TempHeight = SPRITE_GAME_SIZE / 2;
    float TempLeft = ActorLocation.x - SPRITE_GAME_SIZE / 4 + (PlayerDirection.x * SPRITE_GAME_SIZE / 4);
    float TempTop = ActorLocation.y - SPRITE_GAME_SIZE / 4 + (PlayerDirection.y * SPRITE_GAME_SIZE / 4);

    return {TempLeft, TempTop, TempWidth, TempHeight};
}

void Player::AddPoint()
{
    ++PointCount;
    std::string PointText = std::to_string(PointCount) + " / " + std::to_string(GLevelSubsystem->PointCountOnLevel);
    PointCountWidget->UpdateState(PointText);
    GAudioSubsystem->CreateNewSound("point_sound");
}

int Player::GetPointCount()
{
    return PointCount;
}

void Player::AddStar()
{
    ++StarCount;
    std::string StarText = std::to_string(StarCount) + " / " + std::to_string(GLevelSubsystem->StarCountOnLevel);
    StarCountWidget->UpdateState(StarText);
    GAudioSubsystem->CreateNewSound("point_sound");
}

int Player::GetStarCount()
{
    return StarCount;
}

void Player::GetDamage()
{
    ActorSprite->SetColor(sf::Color::Red);
    GAudioSubsystem->CreateNewSound("death_sound");
    CanAction = false;
    GEngine->SwitchState<LevelInstance>();
}
