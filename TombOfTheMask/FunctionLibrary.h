#pragma once
#include "CoreMinimal.h"
#include "Actor.h"
#include "LevelSubsystem.h"
#include <numbers>
#include "GarbageCollector.h"
#include <algorithm>
#include <memory>
#include <typeinfo>


template<typename T>
inline std::shared_ptr<T> SpawnActor(sf::Vector2f cellPosition, float rotationAngle = 0.f)
{
	static_assert(std::is_base_of < Actor, T > ::value, "Class is not child of Actor");

	sf::Vector2f WorldPosition = { cellPosition.x * SPRITE_GAME_SIZE, cellPosition.y * SPRITE_GAME_SIZE };
	auto TempActor = std::make_shared<T>(WorldPosition, rotationAngle);
	GLevelSubsystem->ActorsOnLevel.emplace_back(TempActor);

	TempActor->BeginPlay();

	return TempActor;
}

inline sf::Vector2f RotateVector(sf::Vector2f baseVector, float rotationAngle)
{
	const float rotationInRadians = rotationAngle * (float)std::numbers::pi / 180.f;
	float sinAngle = std::sin(rotationInRadians);
	float cosAngle = std::cos(rotationInRadians);

	return sf::Vector2f(baseVector.x * cosAngle - baseVector.y * sinAngle, baseVector.x * sinAngle + baseVector.y * cosAngle);
}

template<typename T>
inline void ClearVectorForExpiredPtr(std::vector<std::weak_ptr<T>> vec)
{
	auto iter = std::remove_if(vec.begin(), vec.end(),
		[](const std::weak_ptr<T>& pointer) { return pointer.expired(); });
	vec.erase(iter, vec.end());
}

template<typename T, typename K>
inline bool isClassOf(const std::shared_ptr<K>& object)
{
	return object && std::dynamic_pointer_cast<T>(object) != nullptr;
}