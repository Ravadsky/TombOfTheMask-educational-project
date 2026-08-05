#include "Archer.h"

#include "Arrow.h"

#include "ActorFunctions.h"
#include "MathFunctions.h"

#include "AudioSubsystem.h"
#include "PhysicsSubsystem.h"

Archer::Archer(sf::Vector2f position, float rotationAngle) : Actor(ActorType::Archer, position, rotationAngle)
{
    CellPosition = position / (float)SPRITE_GAME_SIZE;
    Collision = CollisionPreset::Block;
    bCanTick = true;
}

void Archer::Update()
{
    if (GPhysicsSubsystem != nullptr)
    {
        timer += GPhysicsSubsystem->GetElapsedTime();
        if (timer > 1.6f)
        {
            timer -= 1.6f;

            sf::Vector2f ArrowOffset = RotateVector({1.f, 0.f}, ActorRotation);
            std::weak_ptr<Arrow> arrowPtr = SpawnActor<Arrow>(CellPosition + ArrowOffset, ActorRotation);

            if (auto _arrow = arrowPtr.lock())
            {
                _arrow->BeginPlay();
            }
            GAudioSubsystem->CreateNewSound("archer_sound");
        }
    }
}
