#include "Archer.h"
#include "PhysicsSubsystem.h"
#include "FunctionLibrary.h"
#include "Arrow.h"

Archer::Archer(sf::Vector2f position) : Archer(position, 0.f) {}

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
		timer += GPhysicsSubsystem->GetElapsedTime();
		if (timer >= 2)
		{
			timer -= 2;
			SpawnActor<Arrow>(CellPosition + RotateVector({ 1.f, 0.f }, ActorRotation), ActorRotation);
		}
	}

}

void Archer::OnCollision(std::weak_ptr<Actor> OtherActor)
{
}
