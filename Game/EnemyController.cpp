#include "EnemyController.h"

const float EnemyController::xTravel = Game::WIDTH/4;

EnemyController::EnemyController(const char* texturesheet, float x, float y) :GameObject(texturesheet, x, y, 15, 15, 2.0f), xStart(x) {
	movementSpeed = 100.0f;
	
}

void EnemyController::Update()
{
	move();
	GameObject::Update();

}

void EnemyController::Render() {
	GameObject::Render();

	/*SDL_SetRenderDrawColor(Game::renderer, 255, 255, 255, 255);
	SDL_RenderDrawLine(Game::renderer, xStart + (textureWidth * textureUpscale)/2, 0, xStart + (textureWidth * textureUpscale) / 2, 100);
	SDL_SetRenderDrawColor(Game::renderer, 255, 10, 10, 255);
	SDL_RenderDrawLine(Game::renderer, Game::WIDTH/2, 0, Game::WIDTH/2, 400);*/

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
