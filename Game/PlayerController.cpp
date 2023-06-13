#include "PlayerController.h"

PlayerController::PlayerController(const char* texturesheet, float x, float y) :GameObject(texturesheet, x, y) {
	movementSpeed = 400.0f;
}

 void PlayerController::Update() 
{
	 //// A simple statement to make the game lag
	 for (int w = 10000000; w > 0; w--);

	 if (Input::GetKeyDown(SDL_SCANCODE_A)) {
		x -= movementSpeed * Game::deltaTime;

	 }

	 if (Input::GetKeyDown(SDL_SCANCODE_D)) {
		 x += movementSpeed * Game::deltaTime;

	 }

	 if (Input::GetKeyDown(SDL_SCANCODE_SPACE)) {
		 std::cout << " SPACE pressed" << std::endl;

	 }


	

	GameObject::Update();
	
}
