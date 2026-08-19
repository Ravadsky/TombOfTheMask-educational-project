#pragma once
#include "CoreMinimal.h"
#include <numbers>

template <typename T>
inline T Clamp(T& Object, T min, T max)
{
    if (min > Object)
        return min;
    if (Object > max)
        return max;
    return Object;
}

inline sf::Vector2f RotateVector(sf::Vector2f baseVector, float rotationAngle)
{
    const float rotationInRadians = rotationAngle * (float)std::numbers::pi / 180.f;
    float sinAngle = std::sin(rotationInRadians);
    float cosAngle = std::cos(rotationInRadians);

    return sf::Vector2f(baseVector.x * cosAngle - baseVector.y * sinAngle,
                        baseVector.x * sinAngle + baseVector.y * cosAngle);
}

template <typename T>
inline void RemoveFromVectorByRef(std::vector<T>& vector, T item)
{
    auto objectIterator = std::find(vector.begin(), vector.end(), item);
    if (objectIterator != vector.end())
        vector.erase(objectIterator);
}