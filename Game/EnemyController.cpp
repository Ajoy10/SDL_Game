#include "EnemyController.h"
#include "Weapon.h"
#include "EnemyManager.h"
#include "MediaManager.h"

const float EnemyController::xTravel = Game::WIDTH/4;
const int EnemyController::horizontalMovementTriggerCount = 1;
int EnemyController::timeDeductDelta = 1500; // 1.5s




EnemyController::EnemyController(const char* texturesheet, float x, float y) :GameObject("Enemy",texturesheet, x, y, 15, 15, 2.0f), xStart(x) {
	movementSpeed = 100.0f;
	GameObject::SetCollisionBox(textureHeight * textureUpscale, textureWidth * textureUpscale);
	GameObject::RegisterGameObject(this);
	weapon = new Weapon(100, Bullet::BulletType::ENEMY_BULLET);
	lastWeaponFire = 0;
}

void EnemyController::Update()
{
	move();
	GameObject::Update();
	if (canShoot && SDL_GetTicks() > lastWeaponFire + EnemyManager::weaponFireFreezeTime) {
		AttemptShoot();
	}

	if (SDL_GetTicks() > (lastScoreDeductTick + timeDeductDelta)) {
		Game::ReduceScore(5);
		lastScoreDeductTick = SDL_GetTicks();
	}


}

void EnemyController::Render() {
	GameObject::Render();

	if (Game::displayGizmos) {

		if (canShoot) {
			SDL_SetRenderDrawColor(Game::renderer, 0, 255, 0, 255);
			SDL_RenderDrawRect(Game::renderer, &collisionBox);
		}
	}
	
	

}

void EnemyController::Destroy()
{
	// Setting destroy animation
	AnimationParams newParams;
	newParams.animationIndex = 1;
	newParams.animationLoop = false;
	newParams.animationFrames = 5;
	newParams.animationStartTick = SDL_GetTicks();
	GameObject::ChangeAnimationParams(newParams);
	animated = true;
	// Passing the ability to shoot to other enemy
	if (canShoot) {
		Game::enemyManager->PassEnemyShootingAbility(enemyIndexX, enemyIndexY);
	}
	Game::enemyManager->EnemyDead(this);

	// Disabling collision so that no other bullet will try to collide and destroy the object
	hasCollision = false;
	MediaManager::PlayAudioOnce("explosion");
	// Adding enemy to destroy pool with delay
	GameObject::DestroyGameObject(this, 450);
}

void EnemyController::AttemptShoot()
{
	int rng = rand() % 100;
	if (rng < EnemyManager::enemyShootingChance) {
		bool shot = weapon->Shoot(x,y + (textureHeight * textureUpscale) + 1.0, 0.0f, EnemyManager::enemyBulletSpeed);
		if (shot) {
			MediaManager::PlayAudioOnce("enemy_shooting");
		}
	}
	lastWeaponFire = SDL_GetTicks() + rand()%100; // Adding a small randomness so that the enemy shooting looks more varied

}



void EnemyController::move() {
	x += direction * movementSpeed * Game::deltaTime;

	// substracting the actual width of texture since origin of the object is at top left
	const float right_limit = (xStart + EnemyController::xTravel) - GameObject::textureWidth * GameObject::textureUpscale;
	const float left_limit = (xStart - EnemyController::xTravel) - GameObject::textureWidth * GameObject::textureUpscale;


	if (x >= right_limit) {
		x = right_limit;
		direction = -1;
	}
	else if (x <= left_limit) {
		x = left_limit;
		direction = 1;
		horizontalMovementCounter++;
	}

	if (horizontalMovementCounter >= EnemyController::horizontalMovementTriggerCount) {
		y += textureHeight*textureUpscale;
		horizontalMovementCounter = 0;
	}

	// Checking whether enemy has crossed the player line
	if (y > Game::playerZoneY) {
		Game::GameOver();
	}
}
