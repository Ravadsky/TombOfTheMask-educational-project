#include "ColliderComponent.h"
#include "Actors/Actor.h"
#include "World/World.h"
#include "World/PhysicsSubsystem.h"

UColliderComponent::UColliderComponent(AActor* componentOwner) : USceneComponent(componentOwner)
{
    CollisionBox = { location.x - SPRITE_GAME_SIZE / 2, location.y - SPRITE_GAME_SIZE / 2, SPRITE_GAME_SIZE,
                     SPRITE_GAME_SIZE };

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