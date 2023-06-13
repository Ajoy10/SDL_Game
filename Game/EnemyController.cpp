#include "EnemyController.h"

const float EnemyController::xTravel = Game::WIDTH/3;

EnemyController::EnemyController(const char* texturesheet, float x, float y) :GameObject(texturesheet, x, y, 15, 15, 3.0f), xStart(x) {
	movementSpeed = 100.0f;
	
}

void EnemyController::Update()
{
	move();
	GameObject::Update();

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

	}
}
