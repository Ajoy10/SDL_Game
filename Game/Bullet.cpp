#include "Bullet.h"

SDL_Texture* Bullet::bulletTexture = nullptr;

SDL_Texture* Bullet::GetBulletTexture() {
	if (!Bullet::bulletTexture)
		Bullet::bulletTexture = TextureManager::LoadTexture("assets/bullet.png");

	return Bullet::bulletTexture;
}

Bullet::Bullet(float x, float y, float xDelta, float yDelta):GameObject("Bullet",Bullet::GetBulletTexture(), x, y) {
	
	this->xDelta = xDelta;
	this->yDelta = yDelta;
	GameObject::RegisterGameObject(this);
	std::cout << "Registered a bullet" << std::endl;
}

void Bullet::Update() {
	x += xDelta * Game::deltaTime;
	y += yDelta * Game::deltaTime;
	GameObject::Update();
	// Has the bullet collided with the player
	// Has the bullet collided with any of the enemy
	// Has the bullet collided with any other bullet
}