#pragma once
#include "GameObject.h"
#include "Input.h"
class PlayerController :
    public GameObject
{
public:
    PlayerController(const char* texturesheet, float x, float y);

    void Update();
private:
    float movementSpeed;
};

