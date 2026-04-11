#pragma once
#include "UObject.h"

class SpriteComponent;

class CheckBox : public UObject
{
  private:
    sf::Texture TextureOn, TextureOff;
    std::unique_ptr<SpriteComponent> Sprite;
    
    bool CurrentState;

  public:
    CheckBox(std::string SpriteOn, std::string SpriteOff, sf::Vector2f pos);

    bool CheckWithCollisions(int xMousePos, int yMousePos);

    void SetInitState(bool State);
    bool ChangeState();
};
