#pragma once
#include <vector>
#include "Bullet.h"
class Weapon
{
private:
	std::vector<Bullet> bullets;
	int maxBullets;
public:
	Weapon();
	Weapon(int maxBullets);
	void Update();
	void Render();

	bool Shoot(float x, float y, float xDelta, float yDelta);
};
