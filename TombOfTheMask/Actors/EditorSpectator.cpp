#include "EditorSpectator.h"
#include "Components/ColliderComponent.h"
#include "Components/InputComponent.h"
#include "Components/MovementComponent.h"
#include "Components/CameraComponent.h"

AEditorSpectator::AEditorSpectator(UWorld* InWorld) : AActor(InWorld)
{
    MovementComponent = AddNewComponent<UMovementComponent>();
    InputComponent = AddNewComponent<UInputComponent>();
    CameraComponent = AddNewComponent<UCameraComponent>();

    ColliderComponent->SetCollisionPreset(ECollisionPreset::Ignore);
}
