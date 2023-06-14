#include "Bullet.h"

SDL_Texture* Bullet::bulletTexture = nullptr;

SDL_Texture* Bullet::GetBulletTexture() {
	if (!Bullet::bulletTexture)
		Bullet::bulletTexture = TextureManager::LoadTexture("assets/bullet.png");

	return Bullet::bulletTexture;
}

Bullet::Bullet(float x, float y, float xDelta, float yDelta):GameObject(Bullet::GetBulletTexture(), x, y) {
	
	this->xDelta = xDelta;
	this->yDelta = yDelta;

}

void Bullet::Update() {
	x += xDelta * Game::deltaTime;
	y += yDelta * Game::deltaTime;
	GameObject::Update();
}