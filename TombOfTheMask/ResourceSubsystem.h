#pragma once
#include "UObject.h"
#include <unordered_map>
#include "functional"
#include "FunctionLibrary.h"

class ResourceSubsystem : public UObject
{
  public:
    sf::Texture SpriteSheet;
    sf::Font GameFont;

    std::unordered_map<int, std::function<std::weak_ptr<Actor>(sf::Vector2f, float)>> ActorsID;

    ResourceSubsystem();

    template <typename T> inline void AddBindActorID(int ID)
    {
        ActorsID[ID] = [](sf::Vector2f pos, float rotation) { return SpawnActor<T>(pos, rotation); };
    }
};
