#pragma once
#include "Core/UObject.h"

#include "Components/SpriteComponent.h"

class UWorld;
class UActorComponent;
class USceneComponent;
class UColliderComponent;
class USpriteComponent;

class AActor : public UObject
{
private:
    UWorld* World;
    USceneComponent* RootComponent;

    std::vector<UActorComponent*> Components;

protected:
    USceneComponent* SceneComponent;
    UColliderComponent* ColliderComponent;
    USpriteComponent* SpriteComponent;

public:
    AActor(UWorld* InWorld);
    virtual ~AActor() override;

    virtual void BeginPlay() override;
    virtual void Update(float deltaTime) override;

    inline UWorld* GetWorld() const { return World; };

    sf::Vector2f GetActorLocation() const;
    void SetActorLocation(sf::Vector2f newLocation);
    void AddWorldOffset(sf::Vector2f offset);

    float GetActorRotation() const;
    void SetActorRotation(float newRotation);

    sf::Vector2f GetActorScale() const;
    void SetActorScale(sf::Vector2f newScale);

    // component methods
    template <typename componentClass>
    componentClass* AddNewComponent()
    {
        static_assert(std::is_base_of_v<UActorComponent, componentClass>, "class must be derived from UActorComponent");

        componentClass* newComponent = new componentClass(this);
        Components.push_back(newComponent);
        newComponent->BeginPlay();

        return newComponent;
    }

    template <typename componentClass>
    componentClass* GetComponentByClass()
    {
        static_assert(std::is_base_of_v<UActorComponent, componentClass>, "class must be derived from UActorComponent");

        for (UActorComponent* comp : Components)
        {
            auto castedComp = dynamic_cast<componentClass*>(comp);
            if (castedComp != nullptr)
                return castedComp;
        }
        return nullptr;
    }

    template <typename componentClass>
    void RemoveComponentByClass()
    {
        static_assert(std::is_base_of_v<UActorComponent, componentClass>, "class must be derived from UActorComponent");

        for (auto iterator = Components.begin(); iterator != Components.end(); ++iterator)
        {
            delete *iterator;
            Components.erase(iterator);
        }
    }
};
