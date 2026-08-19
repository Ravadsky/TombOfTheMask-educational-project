#pragma once
#include "GameSubsystem.h"
#include <unordered_map>

class AActor;
class UWorld;

class UResourceSubsystem : public UGameSubsystem
{
public:
    UResourceSubsystem();

    void LoadSpriteFromSpriteSheet(const std::string& spriteName, int row, int column);

    void LoadSpriteSheet(const std::string& filename);
    void LoadGUISprite(const std::string& filename);

    void LoadGameFont(const std::string& filename);
    void LoadSoundBuffer(const std::string& filename);

    const sf::Texture& GetTexture(const std::string& textureName);
    const sf::SoundBuffer& GetSoundBuffer(const std::string& soundName);
    const sf::Font& GetFont();

private:
    sf::Texture SpriteSheet;
    sf::Font GameFont;
    std::unordered_map<std::string, sf::Texture> StaticSprites;
    std::unordered_map<std::string, sf::SoundBuffer> SoundBuffers;

    std::unordered_map<int, std::function<AActor*(UWorld*)>> ID_ActorFactory;
    std::unordered_map<int, std::string> ID_ActorTextureNames;
    std::vector<int> staticObjectsID;

public:
    inline std::vector<int>& GetStaticObjectsID() { return staticObjectsID; }
    template <typename T>
    void RegisterByID(int id, std::string textureName, bool isStatic = true)
    {
        ID_ActorFactory[id] = [](UWorld* World) -> AActor* { return new T(World); };
        ID_ActorTextureNames[id] = textureName;
        if (isStatic)
            staticObjectsID.push_back(id);
    }
    inline std::string GetTextureNameByID(int id) const { return ID_ActorTextureNames.at(id); };
    inline AActor* Create(int id, UWorld* World) const
    {
        auto it = ID_ActorFactory.find(id);
        return (it != ID_ActorFactory.end()) ? it->second(World) : nullptr;
    }
};
