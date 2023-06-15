#include "Weapon.h"

bool Weapon::Shoot(float x, float y, float xDelta, float yDelta) {
	if(bullets.size() < maxBullets)
	{
		bullets.push_back(Bullet(x, y, xDelta, yDelta));
		return true;
	}
	else {
		return false;
	}
}

void Weapon::Update() {
	for (int i = 0; i < bullets.size(); i++) {
		bullets.at(i).Update();
	}
}

void Weapon::Render() {
	for (int i = 0; i < bullets.size(); i++) {
		bullets.at(i).Render();
	}
}

Weapon::Weapon() {
	this->maxBullets = 5;
}

Weapon::Weapon(int maxBullets) {
	this->maxBullets = maxBullets;
}