#include "Weapon.h"


bool Weapon::Shoot(float x, float y, float xDelta, float yDelta) {
	if(usedBulletsCount < maxBullets)
	{
		Bullet *b = new Bullet(x, y, xDelta, yDelta, bulletType);
		usedBulletsCount++;
		return true;
	}
	else {
		return false;
	}
}

void Weapon::AddBullet()
{
	this->usedBulletsCount--;
}


Weapon::Weapon() {
	this->maxBullets = 5;
}

Weapon::Weapon(int maxBullets) {
	this->maxBullets = maxBullets;
}

Weapon::Weapon(int maxBullets, Bullet::BulletType type)
{
	this->maxBullets = maxBullets;
	this->bulletType = type;
}
