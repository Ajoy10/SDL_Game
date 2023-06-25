#pragma once
#include <vector>
class Weapon
{
private:
	
	int usedBulletsCount = 0;
	int maxBullets;
public:
	Weapon();
	Weapon(int maxBullets);
	

	bool Shoot(float x, float y, float xDelta, float yDelta);
	void AddBullet();
};
