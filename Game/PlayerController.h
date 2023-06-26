#pragma once
#include "GameObject.h"
#include "Input.h"
#include "Weapon.h"

class PlayerController :
    public GameObject
{
public:
    PlayerController(const char* texturesheet, float x, float y);
    Weapon weapon;
    void Update();
    void TakeHit();
private:
    float movementSpeed;
    Uint16 lastWeaponFire;
    static int weaponFireFreezeTime;
    void move(float xInput);
    int health = 3;
};

