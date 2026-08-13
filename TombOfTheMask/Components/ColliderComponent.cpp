#include "ColliderComponent.h"
#include "Actors/Actor.h"
#include "World/World.h"
#include "World/PhysicsSubsystem.h"

UColliderComponent::UColliderComponent(AActor* componentOwner) : USceneComponent(componentOwner)
{
    bCanTick = true;

    auto loc = GetWorldLocation();

    float halfedSizeX = (SPRITE_GAME_SIZE * 0.5f) * scale.x;
    float halfedSizeY = (SPRITE_GAME_SIZE * 0.5f) * scale.y;
    CollisionBox = { loc.x - halfedSizeX, loc.y - halfedSizeY, halfedSizeX * 2, halfedSizeY * 2 };

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
    float halfedSizeX = (SPRITE_GAME_SIZE * 0.5f) * scale.x;
    float halfedSizeY = (SPRITE_GAME_SIZE * 0.5f) * scale.y;
    CollisionBox = { loc.x - halfedSizeX, loc.y - halfedSizeY, halfedSizeX * 2, halfedSizeY * 2 };
}
