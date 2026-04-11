#include "Point.h"

#include "ActorFunctions.h"
#include "Player.h"

Point::Point(sf::Vector2f position, float rotationAngle) : Actor(ActorType::Point, position, rotationAngle)
{
    Collision = CollisionPreset::Overlap;
    ActorSprite->SetDrawType(DrawType::Dynamic);
}

void Point::OnCollision(std::weak_ptr<Actor> OtherActor)
{

    if (auto ActorPtr = OtherActor.lock())
    {
        if (isClassOf<Player>(ActorPtr))
        {
            CastTo<Player>(ActorPtr)->AddPoint();
            MarkToKill();
        }
    }
}
