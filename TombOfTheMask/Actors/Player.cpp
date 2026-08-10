#include "Player.h"

#include "Components/ColliderComponent.h"
#include "Components/InputComponent.h"
#include "Components/MovementComponent.h"

#include "AudioSubsystem.h"
#include "LevelSubsystem.h"

#include "Arrow.h"
#include "LevelInstance.h"

void APlayer::Update(float deltaTime)
{
    UpdateLocation(PlayerDirection * (float)PLAYER_SPEED);
}

APlayer::APlayer(UWorld* InWorld) : AActor(InWorld)
{
    bCanTick = true;

    MovementComponent = AddNewComponent<UMovementComponent>();
    InputComponent = AddNewComponent<UInputComponent>();
    CameraComponent = AddNewComponent<UCameraComponent>();

    ColliderComponent->SetCollisionPreset(ECollisionPreset::Block);

    SpriteComponent->SetSpriteTexture("player");

    // CollisionBox = { position.x - SPRITE_GAME_SIZE / 4, position.y - SPRITE_GAME_SIZE / 4, SPRITE_GAME_SIZE / 2,
    //                  SPRITE_GAME_SIZE / 2 };
}

void APlayer::BeginPlay()
{
    std::string PointText = std::to_string(PointCount) + " / " + std::to_string(GLevelSubsystem->PointCountOnLevel);
    PointCountWidget = std::make_unique<Widget>(sf::Vector2f(64, 64), "Point", PointText);

    std::string StarText = std::to_string(StarCount) + " / " + std::to_string(GLevelSubsystem->StarCountOnLevel);
    StarCountWidget = std::make_unique<Widget>(sf::Vector2f(64, 128), "Star", StarText);
}

void APlayer::OnCollision(std::weak_ptr<Actor> OtherActor)
{
    if (auto other = OtherActor.lock())
    {
        if (other.get() != this)
        {
            auto preset = other->GetCollisionPreset();
            switch (preset)
            {
                case CollisionPreset::Block:
                    UpdateLocation({ -PlayerDirection.x * PLAYER_SPEED, -PlayerDirection.y * PLAYER_SPEED });
                    PlayerDirection = { 0.f, 0.f };
                    if (isClassOf<Arrow>(other))
                        CanAction = false;
                    else
                        CanAction = true;
                    break;
            }
        }
    }
}

void APlayer::SetDirection(MoveDirection Direction)
{
    if (CanAction)
        switch (Direction)
        {
            case MoveDirection::Up:
                PlayerDirection = { 0.f, -1.f };
                CanAction = false;
                ActorSprite->SetRotation(90.f);
                ActorSprite->Flip(true);
                break;
            case MoveDirection::Down:
                PlayerDirection = { 0.f, 1.f };
                CanAction = false;
                ActorSprite->SetRotation(90.f);
                ActorSprite->Flip(false);
                break;
            case MoveDirection::Left:
                PlayerDirection = { -1.f, 0.f };
                CanAction = false;
                ActorSprite->SetRotation(0.f);
                ActorSprite->Flip(true);
                break;
            case MoveDirection::Right:
                PlayerDirection = { 1.f, 0.f };
                CanAction = false;
                ActorSprite->SetRotation(0.f);
                ActorSprite->Flip(false);

                break;
            case MoveDirection::NoDirection:
                PlayerDirection = { 0.f, 0.f };
        }
}

void APlayer::UpdateLocation(sf::Vector2f position)
{
    ActorLocation += position;
    ActorSprite->SetPosition(ActorLocation);
}

sf::FloatRect APlayer::GetCollisionBox()
{

    float TempWidth = SPRITE_GAME_SIZE / 2;
    float TempHeight = SPRITE_GAME_SIZE / 2;
    float TempLeft = ActorLocation.x - SPRITE_GAME_SIZE / 4 + (PlayerDirection.x * SPRITE_GAME_SIZE / 4);
    float TempTop = ActorLocation.y - SPRITE_GAME_SIZE / 4 + (PlayerDirection.y * SPRITE_GAME_SIZE / 4);

    return { TempLeft, TempTop, TempWidth, TempHeight };
}

void APlayer::AddPoint()
{
    ++PointCount;
    std::string PointText = std::to_string(PointCount) + " / " + std::to_string(GLevelSubsystem->PointCountOnLevel);
    PointCountWidget->UpdateState(PointText);
    GAudioSubsystem->CreateNewSound("point_sound");
}

int APlayer::GetPointCount()
{
    return PointCount;
}

void APlayer::AddStar()
{
    ++StarCount;
    std::string StarText = std::to_string(StarCount) + " / " + std::to_string(GLevelSubsystem->StarCountOnLevel);
    StarCountWidget->UpdateState(StarText);
    GAudioSubsystem->CreateNewSound("point_sound");
}

int APlayer::GetStarCount()
{
    return StarCount;
}

void APlayer::GetDamage()
{
    ActorSprite->SetColor(sf::Color::Red);
    GAudioSubsystem->CreateNewSound("death_sound");
    CanAction = false;
    GetEngine->SwitchState<LevelInstance>();
}
