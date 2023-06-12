#include "PlayerController.h"

 void PlayerController::Update() 
{
	if (Game::event.type == SDL_KEYDOWN) {
		switch (Game::event.key.keysym.sym)
		{
		case SDLK_a:
			x -= 10;
			std::cout << "A pressed" << std::endl;
			break;
		case SDLK_d:
			x += 10;
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
