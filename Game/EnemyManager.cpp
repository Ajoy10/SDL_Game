#include "EnemyManager.h"

int EnemyManager::maxInALayer = 6;
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
		enemies.push_back(EnemyController("assets/enemy_one.png", xInit , yInit));
		countInCurrentLayer++;
	}
}

void EnemyManager::Update()
{
	for (int i = 0; i < enemies.size(); i++) {
		enemies.at(i).Update();
	}
}

void EnemyManager::Render()
{
	for (int i = 0; i < enemies.size(); i++) {
		enemies.at(i).Render();
	}
}