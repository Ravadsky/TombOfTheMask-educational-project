#pragma once
#include "GameSubsystem.h"

class USpriteComponent;
class UUserWidget;
class UCameraComponent;

class URenderSubsystem : public UGameSubsystem
{
private:
    UCameraComponent* CurrentCameraComponent = nullptr;
    sf::Vector2f CameraOrigin;

public:
    std::vector<USpriteComponent*> ActorsToDraw;

    std::vector<UUserWidget*> WidgetsToDraw;

    URenderSubsystem();
    virtual void Update(float deltaTime) override;

    inline void RegisterCamera(UCameraComponent* camera) { CurrentCameraComponent = camera; }
    inline void UnregisterCamera(UCameraComponent* camera)
    {
        if (CurrentCameraComponent == camera)
            CurrentCameraComponent = nullptr;
    }
};
