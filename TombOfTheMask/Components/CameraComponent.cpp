#include "CameraComponent.h"
#include "Core/GameSubsystems/RenderSubsystem.h"

UCameraComponent::UCameraComponent(AActor* componentOwner) : UActorComponent(componentOwner)
{
    GetRenderSubsystem()->RegisterCamera(this);
}

UCameraComponent::~UCameraComponent()
{
    GetRenderSubsystem()->UnregisterCamera(this);
}
