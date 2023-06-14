#pragma once
#include <vector>
#include "Bullet.h"
class Weapon
{
private:
	std::vector<Bullet> bullets;
public:
	Weapon();
	void Update();
	void Render();

	void Shoot(float x, float y, float xDelta, float yDelta);
};
