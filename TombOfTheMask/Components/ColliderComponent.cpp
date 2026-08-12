#include "ColliderComponent.h"
#include "Actors/Actor.h"
#include "World/World.h"
#include "World/PhysicsSubsystem.h"

UColliderComponent::UColliderComponent(AActor* componentOwner) : USceneComponent(componentOwner)
{
    bCanTick = true;

    auto loc = GetWorldLocation();
    CollisionBox = { loc.x - SPRITE_GAME_SIZE / (scale.x * 2), loc.y - SPRITE_GAME_SIZE / (scale.y * 2),
                     SPRITE_GAME_SIZE, SPRITE_GAME_SIZE };

    Owner->GetWorld()->GetPhysicsSubsystem()->AddTriggerComponent(this);
}

UColliderComponent::~UColliderComponent()
{
    Owner->GetWorld()->GetPhysicsSubsystem()->RemoveTriggerComponent(this);
}

void UColliderComponent::OnCollision(UColliderComponent* otherCollider)
{
    onCollision.Broadcast(otherCollider);
}

void UColliderComponent::Update(float deltaTime)
{
    auto loc = GetWorldLocation();
    CollisionBox = { loc.x - SPRITE_GAME_SIZE / (scale.x * 2), loc.y - SPRITE_GAME_SIZE / (scale.y * 2),
                     SPRITE_GAME_SIZE, SPRITE_GAME_SIZE };
}
