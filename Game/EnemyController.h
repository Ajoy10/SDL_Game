#pragma once
#include "GameObject.h"
class EnemyController : public GameObject
{
public:
    EnemyController(const char* texturesheet, float x, float y);

    void Update();
    void Render();

private:
    float movementSpeed;
    short int direction = 1;
    const float xStart;
    static const float xTravel;
    void move();
};


