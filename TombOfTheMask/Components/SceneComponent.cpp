#include "SceneComponent.h"

USceneComponent::USceneComponent(AActor* componentOwner) : UActorComponent(componentOwner) {}

sf::Vector2f USceneComponent::GetWorldLocation()
{
    if (Parent != nullptr)
    {
        sf::Vector2f parentLocation = Parent->GetWorldLocation();
        float parentRototation = Parent->GetWorldRotation();
        sf::Vector2f rotated = RotateVector(location, parentRototation);
        return parentLocation + rotated;
    }
    return location;
}

sf::Vector2f USceneComponent::GetWorldScale()
{
    if (Parent != nullptr)
    {
        sf::Vector2f parentScale = Parent->GetWorldScale();
        return { parentScale.x * scale.x, parentScale.y * scale.y };
    }
    return scale;
}

float USceneComponent::GetWorldRotation()
{
    if (Parent != nullptr)
    {
        return Parent->GetWorldRotation() + rotation;
    }
    return rotation;
}

void USceneComponent::SetWorldLocation(sf::Vector2f newLocation)
{
    if (Parent != nullptr)
    {
        sf::Vector2f parentLocation = Parent->GetWorldLocation();
        float parentRotation = Parent->GetWorldRotation();

        sf::Vector2f delta = newLocation - parentLocation;
        location = RotateVector(delta, -parentRotation);
    }
    location = newLocation;
}

void USceneComponent::SetWorldScale(sf::Vector2f newScale)
{
    if (Parent != nullptr)
    {
        sf::Vector2f parentScale = Parent->GetWorldScale();
        scale = newScale - parentScale;
    }
    scale = newScale;
}

void USceneComponent::SetWorldRotation(float newRotation)
{
    if (Parent != nullptr)
    {
        float parentRotation = Parent->GetWorldRotation();
        rotation = newRotation - parentRotation;
    }
    rotation = newRotation;
}

void USceneComponent::AddWorldOffset(sf::Vector2f offset)
{
    location += offset;
}

void USceneComponent::AttachToComponent(USceneComponent* parent)
{
    assert(parent != nullptr);

    if (Parent != nullptr)
    {
        auto& oldParent_Children = Parent->Children;
        oldParent_Children.erase(std::remove(oldParent_Children.begin(), oldParent_Children.end(), this),
                                 oldParent_Children.end());
    }
    sf::Vector2f WorldLocation = GetWorldLocation();
    float WorldRotation = GetWorldRotation();
    sf::Vector2f WorldScale = GetWorldScale();

    Parent = parent;

    sf::Vector2f ParentWorldLocation = Parent->GetWorldLocation();
    float ParentWorldRotation = Parent->GetWorldRotation();
    sf::Vector2f ParentWorldScale = Parent->GetWorldScale();

    sf::Vector2f DeltaLocation = WorldLocation - ParentWorldLocation;
    location = RotateVector(DeltaLocation, -ParentWorldRotation);
    rotation = WorldRotation - ParentWorldRotation;
    scale = { WorldScale.x / ParentWorldScale.x, WorldScale.y / ParentWorldScale.y };

    Parent->Children.push_back(this);
}
