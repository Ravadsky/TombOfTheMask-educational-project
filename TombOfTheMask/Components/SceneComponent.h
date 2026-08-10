#pragma once
#include "ActorComponent.h"

class USceneComponent : public UActorComponent
{
public:
    USceneComponent(AActor* componentOwner);

    inline sf::Vector2f GetLocalLocation() const { return location; }
    inline sf::Vector2f GetLocalScale() const { return scale; }
    inline float GetLocalRotation() const { return rotation; }

    inline void SetLocalLocation(sf::Vector2f newLocation) { location = newLocation; }
    inline void SetLocalScale(sf::Vector2f newScale) { scale = newScale; }
    inline void SetLocalRotation(float newRotation) { rotation = newRotation; }

    sf::Vector2f GetWorldLocation();
    sf::Vector2f GetWorldScale();
    float GetWorldRotation();

    void SetWorldLocation(sf::Vector2f newLocation);
    void SetWorldScale(sf::Vector2f newScale);
    void SetWorldRotation(float newRotation);

    void AddWorldOffset(sf::Vector2f offset);

    void AttachToComponent(USceneComponent* parent);
    inline USceneComponent* GetParent() const { return Parent; };
    inline std::vector<USceneComponent*>& GetChildren() { return Children; };

protected:
    sf::Vector2f location{ 0.0f, 0.0f };
    sf::Vector2f scale{ 1.0f, 1.0f };
    float rotation{ 0.0f };

    USceneComponent* Parent;
    std::vector<USceneComponent*> Children;
};
