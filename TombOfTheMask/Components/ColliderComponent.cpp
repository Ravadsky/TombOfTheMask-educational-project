#include "ColliderComponent.h"

UColliderComponent::UColliderComponent(AActor* componentOwner) : USceneComponent(componentOwner)
{
    CollisionBox = { location.x - SPRITE_GAME_SIZE / 2, location.y - SPRITE_GAME_SIZE / 2, SPRITE_GAME_SIZE,
                     SPRITE_GAME_SIZE };
}

void UColliderComponent::OnCollision(UColliderComponent* otherCollider)
{
    onCollision.Broadcast(otherCollider);
}