#include "CameraComponent.h"
#include "Core/GameSubsystems/RenderSubsystem.h"
#include "Actors/Actor.h"

UCameraComponent::UCameraComponent(AActor* componentOwner) : UActorComponent(componentOwner)
{
    GetRenderSubsystem()->RegisterCamera(this);

    float halfCellSize = SPRITE_GAME_SIZE / 2;
    MinCameraPos = { CAMERA_PIVOT.x - halfCellSize, CAMERA_PIVOT.y - halfCellSize };
    MaxCameraPos = { (float)LEVEL_SIZE * SPRITE_GAME_SIZE - CAMERA_PIVOT.x - halfCellSize,
                     (float)LEVEL_SIZE * SPRITE_GAME_SIZE - CAMERA_PIVOT.y - halfCellSize };
}

UCameraComponent::~UCameraComponent()
{
    GetRenderSubsystem()->UnregisterCamera(this);
}

sf::Vector2f UCameraComponent::GetCameraPosition()
{
    auto CameraPos = Owner->GetActorLocation();
    float CameraX = Clamp(CameraPos.x, MinCameraPos.x, MaxCameraPos.x);
    float CameraY = Clamp(CameraPos.y, MinCameraPos.y, MaxCameraPos.y);
    return { CameraX, CameraY };
}
