#pragma once
#include "GameObject.h"
class PlayerController :
    public GameObject
{
public:
    PlayerController(const char* texturesheet, int x, int y) :GameObject(texturesheet, x, y) {};

    void Update();
};

