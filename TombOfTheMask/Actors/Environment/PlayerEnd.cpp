#include "PlayerEnd.h"

#include "Core/DataFunctions.h"

#include "GameStates/LevelSelector.h"
#include "Actors/Player.h"

#include "Components/ColliderComponent.h"
#include "Core/GameSubsystems/ResourceSubsystem.h"

APlayerEnd::APlayerEnd(UWorld* InWorld) : AActor(InWorld)
{
    ColliderComponent->SetCollisionPreset(ECollisionPreset::Overlap);
    ColliderComponent->onCollision.Add(this, &APlayerEnd::EndLevel);

    SpriteComponent->SetSpriteTexture("player_end");
}

void APlayerEnd::EndLevel(UColliderComponent* otherCollider)
{
    auto actor = otherCollider->GetOwner();
    if (isClassOf<APlayer>(actor))
    {
        auto player = CastTo<APlayer>(actor);
        int LevelIndex = GetDataParameter("CurrentLevel:");

        // Победа в уровне
        std::string key = "Level" + std::to_string(LevelIndex) + ':';
        ChangeDataParamater(key, 1);

        // Сколько звезд собрано
        key = "Level" + std::to_string(LevelIndex) + ".stars:";
        if (player->GetStarCount() > GetDataParameter(key))
        {
            ChangeDataParamater(key, player->GetStarCount());
        }

        // Сколько очков собрано
        key = "Level" + std::to_string(LevelIndex) + ".points:";
        if (player->GetPointCount() > GetDataParameter(key))
        {
            ChangeDataParamater(key, player->GetPointCount());
        }
        Engine->MarkToSwitchState<LevelSelector>();
    }
}