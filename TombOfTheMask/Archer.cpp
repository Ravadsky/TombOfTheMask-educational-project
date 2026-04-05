#include "Archer.h"
#include "Arrow.h"
#include "FunctionLibrary.h"
#include "PhysicsSubsystem.h"

Archer::Archer(sf::Vector2f position) : Archer(position, 0.f)
{
}

Archer::Archer(sf::Vector2f position, float rotationAngle) : Actor(ActorType::Archer, position, rotationAngle)
{
    CellPosition = position / (float)SPRITE_GAME_SIZE;
    Collision = CollisionPreset::Block;
    canTick = true;
}

void Archer::Update()
{
    if (GPhysicsSubsystem != nullptr)
    {
        if (Timer<Archer>(2.f))
        {
            SpawnActor<Arrow>(CellPosition + RotateVector({1.f, 0.f}, ActorRotation), ActorRotation);
        }
    }
}

void Archer::OnCollision(std::weak_ptr<Actor> OtherActor)
{
}
