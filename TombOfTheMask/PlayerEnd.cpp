#include "PlayerEnd.h"
#include "Engine.h"
#include "FunctionLibrary.h"
#include "LevelSelector.h"
#include "Player.h"

PlayerEnd::PlayerEnd(sf::Vector2f position, float rotationAngle) : Actor(ActorType::PlayerEnd, position, rotationAngle)
{
    Collision = CollisionPreset::Overlap;
}

void PlayerEnd::Update()
{
}

void PlayerEnd::OnCollision(std::weak_ptr<Actor> OtherActor)
{
    if (auto other = OtherActor.lock())
    {
        if (isClassOf<Player>(other))
        {
            int LevelIndex = GetDataParameter("CurrentLevel:");

            // Победа в уровне
            std::string key = "Level" + std::to_string(LevelIndex) + ':';
            ChangeDataParamater(key, 1);

            // Сколько звезд собрано
            key = "Level" + std::to_string(LevelIndex) + ".stars:";
            if (CastTo<Player>(other)->GetStarCount() > GetDataParameter(key))
            {
                ChangeDataParamater(key, CastTo<Player>(other)->GetStarCount());
            }

            // Сколько очков собрано
            key = "Level" + std::to_string(LevelIndex) + ".points:";
            if (CastTo<Player>(other)->GetPointCount() > GetDataParameter(key))
            {
                ChangeDataParamater(key, CastTo<Player>(other)->GetPointCount());
            }
            GEngine->SwitchState<LevelSelector>();
        }
    }
}
