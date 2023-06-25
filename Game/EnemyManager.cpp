#include "EnemyManager.h"
#include "Bullet.h"
#include "Weapon.h"


int EnemyManager::maxInALayer = 6;
int EnemyManager::enemyShootingChance = 2;
float EnemyManager::enemyBulletSpeed = 200.0f;
int EnemyManager::weaponFireFreezeTime = 1000;



EnemyManager::EnemyManager(int totalEnemies)
{
	this->totalEnemies = this->enemyCount = totalEnemies;
}

void EnemyManager::Init()
{
	int currentLayer = 0;
	int countInCurrentLayer = 0;
	int currentOffset = 0;
	int totalLayer = (int)(totalEnemies / EnemyManager::maxInALayer);
	for (int i = 0; i < totalEnemies; i++)
	{
		if (countInCurrentLayer >= maxInALayer) {
			countInCurrentLayer = 0;
			currentLayer++;
			currentOffset = 0;
		}
		int maxInCurrentLayer = EnemyManager::maxInALayer;
		if (currentLayer >= totalLayer) {
			maxInCurrentLayer = (totalEnemies % EnemyManager::maxInALayer);
		}
		currentOffset = currentOffset + 1;
		const int xInit = (Game::WIDTH / 2 + (maxInCurrentLayer / 2.0f - currentOffset) * 42) + 9.5f; // +9 is added manually to offset it to center of the screen
		const int yInit = 20 + (currentLayer * 42);
		EnemyController* enemy = new EnemyController("assets/enemy_one.png", xInit, yInit);
		enemies.push_back(enemy);
		enemy->enemyIndexX = countInCurrentLayer;
		enemy->enemyIndexY = currentLayer;
		std::cout << enemy->enemyIndexX << "," << enemy->enemyIndexY << std::endl;
		if (currentLayer == totalLayer) {
			enemy->canShoot = true;
		}
		countInCurrentLayer++;
	}
}

//void EnemyManager::Update()
//{
//	for (int i = 0; i < enemies.size(); i++) {
//		enemies.at(i)->Update();
//	}
//}

void EnemyManager::Render()
{
	for (int i = 0; i < enemies.size(); i++) {
		enemies.at(i)->Render();
	}
}