#include "Actors/Actor.h"
#include "Core/World.h"

#include "Components/SceneComponent.h"
#include "Components/ColliderComponent.h"
#include "Components/SpriteComponent.h"


AActor::AActor(UWorld* InWorld) : UObject()
{
    World = InWorld;

    SceneComponent = AddNewComponent<USceneComponent>();
    RootComponent = SceneComponent;

    ColliderComponent = AddNewComponent<UColliderComponent>();
    ColliderComponent->AttachToComponent(SceneComponent);

    SpriteComponent = AddNewComponent<USpriteComponent>();
}

AActor::~AActor()
{
    for (auto comp : Components)
    {
        delete comp;
    }
    Components.clear();
}

void AActor::BeginPlay() {}

void AActor::Update(float deltaTime) {}

sf::Vector2f AActor::GetActorLocation() const
{
    return RootComponent->GetWorldLocation();
}

void AActor::SetActorLocation(sf::Vector2f newLocation)
{
    RootComponent->SetWorldLocation(newLocation);
}

float AActor::GetActorRotation() const
{
    return RootComponent->GetWorldRotation();
}

void AActor::SetActorRotation(float newRotation)
{
    RootComponent->SetWorldRotation(newRotation);
}

sf::Vector2f AActor::GetActorScale() const
{
    return RootComponent->GetWorldScale();
}

void AActor::SetActorScale(sf::Vector2f newScale)
{
    RootComponent->SetWorldScale(newScale);
}
