#pragma once
#include "GameObject.h"
#include "Input.h"
#include "Weapon.h"

class Text;
class PlayerController :
    public GameObject
{
public:
    PlayerController(const char* texturesheet, float x, float y);
    ~PlayerController();
    Weapon weapon;
    Text* healthText;
    void Update();
    void TakeHit();
private:
    float movementSpeed;
    Uint32 lastWeaponFire;
    static int weaponFireFreezeTime;
    void move(float xInput);
    int health = 3;
};

