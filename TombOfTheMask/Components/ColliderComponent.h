#pragma once
#include "SceneComponent.h"

enum class ECollisionPreset
{
    Ignore,
    Overlap,
    Block,
};

class UColliderComponent : public USceneComponent
{
public:
    UColliderComponent(AActor* componentOwner);
    virtual ~UColliderComponent() override;
    FDelegate<UColliderComponent*> onCollision;
    void OnCollision(UColliderComponent* otherCollider);

    inline sf::FloatRect GetCollisionBox() const { return CollisionBox; };
    inline ECollisionPreset GetCollisionPreset() const { return CollisionPreset; };
    inline void SetCollisionPreset(ECollisionPreset collision) { CollisionPreset = collision; };

private:
    ECollisionPreset CollisionPreset = ECollisionPreset::Ignore;
    sf::FloatRect CollisionBox;
};
