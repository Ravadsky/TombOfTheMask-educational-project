#include "Point.h"
#include "FunctionLibrary.h"
#include "LevelSubsystem.h"
#include "Player.h"

Point::Point(sf::Vector2f position, float rotationAngle) : Actor(ActorType::Point, position, rotationAngle)
{
    Collision = CollisionPreset::Overlap;
    ActorSprite->SetDrawType(DrawType::Dynamic);
}

void Point::Update()
{
}

void Point::OnCollision(std::weak_ptr<Actor> OtherActor)
{

    if (auto other = OtherActor.lock())
    {
        if (other.get() != this)
        {
            if (isClassOf<Player>(other))
            {
                GLevelSubsystem->CurrentPlayer.lock().get()->AddPoint();
                MarkToKill();
            }
        }
    }
}
