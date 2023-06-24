#include "EnemyController.h"

const float EnemyController::xTravel = Game::WIDTH/4;
const int EnemyController::horizontalMovementTriggerCount = 3;



EnemyController::EnemyController(const char* texturesheet, float x, float y) :GameObject("Enemy",texturesheet, x, y, 15, 15, 2.0f), xStart(x) {
	movementSpeed = 100.0f;
	GameObject::SetCollisionBox(textureHeight * textureUpscale, textureWidth * textureUpscale);
	GameObject::RegisterGameObject(this);
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
	// Disabling collision so that no other bullet will try to collide and destroy the object
	hasCollision = false;
	// Adding enemy to destroy pool with delay
	GameObject::DestroyGameObject(this, 450);
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
}
