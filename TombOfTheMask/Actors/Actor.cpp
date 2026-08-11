#include "Actors/Actor.h"

#include "Components/SceneComponent.h"
#include "Components/ColliderComponent.h"
#include "Components/SpriteComponent.h"
#include "World/World.h"

AActor::AActor(UWorld* InWorld) : UObject()
{
    World = InWorld;

    SceneComponent = AddNewComponent<USceneComponent>();
    RootComponent = SceneComponent;

    ColliderComponent = AddNewComponent<UColliderComponent>();
    ColliderComponent->AttachToComponent(SceneComponent);

    SpriteComponent = AddNewComponent<USpriteComponent>();
    SpriteComponent->AttachToComponent(SceneComponent);

    GetWorld()->AddActorToWorld(this);
}

AActor::~AActor()
{
    for (auto comp : Components)
    {
        delete comp;
    }
    Components.clear();

    GetWorld()->RemoveActorFromWorld(this);
}

void AActor::BeginPlay() {}

void AActor::Update(float deltaTime)
{
    for (auto comp : Components)
    {
        comp->Update(deltaTime);
    }
}

sf::Vector2f AActor::GetActorLocation() const
{
    return RootComponent->GetWorldLocation();
}

void AActor::SetActorLocation(sf::Vector2f newLocation)
{
    RootComponent->SetWorldLocation(newLocation);
}

void AActor::AddWorldOffset(sf::Vector2f offset)
{
    RootComponent->AddWorldOffset(offset);
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
