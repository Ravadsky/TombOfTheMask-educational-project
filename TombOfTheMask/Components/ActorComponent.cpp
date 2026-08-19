#include "ActorComponent.h"

UActorComponent::UActorComponent(AActor* componentOwner) : UObject()
{
    Owner = componentOwner;
}
