#pragma once
#include "EnemyController.h"
#include "Game.h"
#include <vector>

class EnemyManager
{
public:
	EnemyManager(int totalEnemies);
	~EnemyManager();
	void Init();
	void Update();
	void Render();
private:
	static int maxInALayer;
	int enemyCount, totalEnemies;
	std::vector<EnemyController> enemies;
	
};

