#include "Bullet.h"
#include "EnemyController.h"
#include "PlayerController.h"
#include <iostream>

SDL_Texture* Bullet::bulletTexture = nullptr;

class PlayerController;
SDL_Texture* Bullet::GetBulletTexture() {
	if (!Bullet::bulletTexture)
		Bullet::bulletTexture = TextureManager::LoadTexture("assets/bullet.png");

	return Bullet::bulletTexture;
}

Bullet::Bullet(float x, float y, float xDelta, float yDelta):GameObject("Bullet",Bullet::GetBulletTexture(), x, y) {
	
	this->xDelta = xDelta;
	this->yDelta = yDelta;
	GameObject::SetCollisionBox(textureWidth * textureUpscale, textureHeight * textureUpscale);
	GameObject::RegisterGameObject(this);
	std::cout << "Registered a bullet" << std::endl;
}

void Bullet::Collided(GameObject* go) {
	std::cout << name << " Destroyed " << go->name << std::endl;
	EnemyController* enemy = dynamic_cast<EnemyController*>(go);
	if (enemy != NULL)
	{
		enemy->Destroy();
	}

	Game::player->weapon.AddBullet();
	GameObject::DestroyGameObject((GameObject*)this);
}

void Bullet::Update() {
	x += xDelta * Game::deltaTime;
	y += yDelta * Game::deltaTime;



	if (y < 0) {
		Game::player->weapon.AddBullet();
		GameObject::DestroyGameObject((GameObject*)this);
	}
	else {
		GameObject::Update();
	}
	
}