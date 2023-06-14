#include "Weapon.h"

void Weapon::Shoot(float x, float y, float xDelta, float yDelta) {
	bullets.push_back(Bullet(x, y, xDelta, yDelta));
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

}