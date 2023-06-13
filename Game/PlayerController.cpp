#include "PlayerController.h"

PlayerController::PlayerController(const char* texturesheet, float x, float y) :GameObject(texturesheet, x, y) {
	movementSpeed = 400.0f;
}

 void PlayerController::Update() 
{
	 //// A simple statement to make the game lag
	 //for (int w = 10000; w > 0; w--);

	 if (Input::GetKeyDown(SDL_SCANCODE_A)) {
		x -= movementSpeed * Game::deltaTime;

	 }

	 if (Input::GetKeyDown(SDL_SCANCODE_D)) {
		 x += movementSpeed * Game::deltaTime;

	 }

	 if (Input::GetKeyDown(SDL_SCANCODE_SPACE)) {
		 std::cout << " SPACE pressed" << std::endl;

	 }


	//if (Game::event.type == SDL_KEYDOWN) {
	//	auto keydown = Game::event.key.keysym.sym;
	//	
	//	if (keydown == SDLK_a)
	//	{
	//		x -= movementSpeed * Game::deltaTime;
	//		//std::cout << "A pressed" << std::endl;
	//	}
	//		
	//	if (keydown == SDLK_d)
	//	{
	//		x += movementSpeed * Game::deltaTime;
	//		//std::cout << "D pressed" << std::endl;
	//	}
	//	if (keydown == SDLK_SPACE)
	//	{
	//		//std::cout << " SPACE pressed" << std::endl;
	//	}
	//	
	//}

	GameObject::Update();
	
}
