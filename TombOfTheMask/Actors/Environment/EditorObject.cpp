#include "EditorObject.h"

#include "Components/ColliderComponent.h"
#include "Core/GameSubsystems/ResourceSubsystem.h"

AEditorObject::AEditorObject(UWorld* InWorld) : AActor(InWorld)
{
    ColliderComponent->SetCollisionPreset(ECollisionPreset::Ignore);

    SpriteComponent->SetSpriteTexture("editor_object");
}