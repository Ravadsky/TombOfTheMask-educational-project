#pragma once
#include "CoreMinimal.h"
#include "Actor.h"

template<typename T>
inline T* SpawnActor(sf::Vector2f ÑellPosition)
{
	static_assert(std::is_base_of < Actor, T > ::value, "T is not child of Actor");
	
	sf::Vector2f WorldPosition = { ÑellPosition.x * SPRITE_GAME_SIZE, ÑellPosition.y * SPRITE_GAME_SIZE };
	return new T(WorldPosition);
}
