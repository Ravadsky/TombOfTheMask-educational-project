#include "Star.h"
#include "FunctionLibrary.h"
#include "LevelSubsystem.h"
#include "Player.h"

Star::Star(sf::Vector2f position, float rotationAngle) : Actor(ActorType::Star, position, rotationAngle)
{
    Collision = CollisionPreset::Overlap;
    ActorSprite->SetDrawType(DrawType::Dynamic);
}

void Star::Update()
{
}

void Star::OnCollision(std::weak_ptr<Actor> OtherActor)
{

    if (auto other = OtherActor.lock())
    {
        if (isClassOf<Player>(other))
        {
            GLevelSubsystem->CurrentPlayer.lock().get()->AddStar();
            MarkToKill();
        }
    }
}
