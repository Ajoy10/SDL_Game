#include "PlayerController.h"

PlayerController::PlayerController(const char* texturesheet, int x, int y) :GameObject(texturesheet, x, y) {
	movementSpeed = 800.0f;
}

 void PlayerController::Update() 
{
	if (Game::event.type == SDL_KEYDOWN) {
		switch (Game::event.key.keysym.sym)
		{
		case SDLK_a:
			x -= movementSpeed * Game::deltaTime;
			std::cout << "A pressed" << std::endl;
			break;
		case SDLK_d:
			x += movementSpeed * Game::deltaTime;
			std::cout << "D pressed" << std::endl;
			break;
		case SDLK_SPACE:
			std::cout << " SPACE pressed" << std::endl;
			break;
		default:
			break;
		}
	}

	GameObject::Update();
	
}
