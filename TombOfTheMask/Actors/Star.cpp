#include "Star.h"

#include "ActorFunctions.h"
#include "Player.h"

Star::Star(sf::Vector2f position, float rotationAngle) : Actor(ActorType::Star, position, rotationAngle)
{
    Collision = CollisionPreset::Overlap;
    ActorSprite->SetDrawType(DrawType::Dynamic);
}

void Star::OnCollision(std::weak_ptr<Actor> OtherActor)
{
    if (auto ActorPtr = OtherActor.lock())
    {
        if (isClassOf<Player>(ActorPtr))
        {
            CastTo<Player>(ActorPtr)->AddStar();
            MarkToKill();
        }
    }
}
