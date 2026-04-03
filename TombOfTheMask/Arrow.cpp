#include "Arrow.h"
#include "FunctionLibrary.h"
#include "PhysicsSubsystem.h"

#include "Wall.h"
#include "Player.h"

Arrow::Arrow(sf::Vector2f position) : Arrow(position, 0.f) {}

Arrow::~Arrow()
{
}

Arrow::Arrow(sf::Vector2f position, float rotationAngle) : Actor(ActorType::Arrow, position, rotationAngle)
{
	canTick = true;
	triggerCollision = true;
	Collision = CollisionPreset::Block;
	ActorSprite->SetDrawType(DrawType::Dynamic);

}

void Arrow::Update()
{
	ActorLocation += RotateVector({ 1.f, 0.f }, ActorRotation) * (float) PLAYER_SPEED / 2.f;
	CollisionBox = { ActorLocation.x - SPRITE_GAME_SIZE / 4, ActorLocation.y - SPRITE_GAME_SIZE / 4, SPRITE_GAME_SIZE / 2, SPRITE_GAME_SIZE / 2 };
	ActorSprite->SetPosition(ActorLocation);
}

void Arrow::BeginPlay()
{
	//необходимо, потому что стрела появляется позже, чем система физики сканирует все объекты на "может триггерить коллизии"
	GPhysicsSubsystem->TriggerActors.emplace_back(shared_from_this());
}

void Arrow::OnCollision(std::weak_ptr<Actor> OtherActor)
{
	if (auto other = OtherActor.lock())
	{
		if (other.get() != this)
		{
			auto preset = other->GetCollisionPreset();
			switch (preset)
			{
			case CollisionPreset::Block:
				if (isClassOf<Player>(other))  GWindow->close();
				MarkToKill();
				break;
			case CollisionPreset::Overlap:

				break;
			case CollisionPreset::Ignore:

				break;
			}
		}
	}

}
