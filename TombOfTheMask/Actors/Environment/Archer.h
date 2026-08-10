#pragma once
#include "Actors/Actor.h"

class AArcher : public AActor
{
  private:
    float timer = 0.f;
    sf::Vector2f CellPosition;

  public:
    AArcher(UWorld* InWorld);

    virtual void Update(float deltaTime) override;
};
