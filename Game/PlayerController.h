#pragma once
#include "GameObject.h"
class PlayerController :
    public GameObject
{
public:
    PlayerController(const char* texturesheet, int x, int y);

    void Update();
private:
    float movementSpeed;
};

