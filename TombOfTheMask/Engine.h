#pragma once
#include "UObject.h"
class Engine :
    public UObject
{
public:
    Engine(sf::RenderWindow& window);

    void BeginPlay() override;
    void Update() override;
};

