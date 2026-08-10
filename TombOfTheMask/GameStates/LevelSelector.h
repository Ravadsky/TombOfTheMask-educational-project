#pragma once
#include "GameState.h"

class UButton;
class ULevelIcon;

class ULevelSelector : public UGameState
{
private:
    std::unique_ptr<UButton> Level1;
    std::unique_ptr<ULevelIcon> Level1Sprite;

    std::unique_ptr<UButton> Level2;
    std::unique_ptr<ULevelIcon> Level2Sprite;

    std::unique_ptr<UButton> Level3;
    std::unique_ptr<ULevelIcon> Level3Sprite;

    sf::Texture LevelTexture;
    sf::Texture CompletedLevelTexture;
    sf::Texture LockedLevelTexture;

public:
    ULevelSelector();
    virtual void Update(float deltaTime) override;

    void ChooseLevel(int index);

    sf::Texture* getLevelSprite(int CurrentLevel);
};
