#include "Spikes.h"

#include "Player.h"
#include "ActorFunctions.h"


Spikes::Spikes(sf::Vector2f position, float rotationAngle) : Actor(ActorType::Spikes, position, rotationAngle)
{
    Collision = CollisionPreset::Block;
}

void Spikes::OnCollision(std::weak_ptr<Actor> OtherActor)
{
    if (auto ActorPtr = OtherActor.lock())
    {
        if (isClassOf<Player>(ActorPtr))
            CastTo<Player>(ActorPtr)->GetDamage();
    }
}
