#pragma once
#include "Actor.h"

class UInputComponent;
class UMovementComponent;
class UCameraComponent;

class AEditorSpectator : public AActor
{
public:
    AEditorSpectator(UWorld* InWorld);

private:
    UInputComponent* InputComponent;
    UMovementComponent* MovementComponent;
    UCameraComponent* CameraComponent;
};
