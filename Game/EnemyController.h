#pragma once
#include "GameObject.h"
class EnemyController : public GameObject
{
public:
    EnemyController(const char* texturesheet, float x, float y);

    void Update();
    void Render();

    void Destroy();

private:
    float movementSpeed;
    short int direction = 1;
    short int horizontalMovementCounter = 0;
    static const int horizontalMovementTriggerCount;
    const float xStart;
    static const float xTravel;
    void move();
};


