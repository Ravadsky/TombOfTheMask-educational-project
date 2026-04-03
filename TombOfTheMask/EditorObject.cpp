#include "EditorObject.h"

EditorObject::EditorObject(sf::Vector2f position, float rotationAngle) : Actor(ActorType::EditorObject, position, rotationAngle)
{
	Collision = CollisionPreset::Ignore;
}

void EditorObject::Update()
{
}

void EditorObject::OnCollision(std::weak_ptr<Actor> OtherActor)
{
}
