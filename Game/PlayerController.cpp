#include "PlayerController.h"

PlayerController::PlayerController(const char* texturesheet, float x, float y) :GameObject(texturesheet, x, y,14,14, 3.0f) {
	movementSpeed = 400.0f;
}

 void PlayerController::Update() 
{
	 //// A simple statement to make the game lag
	 // for (int w = 10000000; w > 0; w--);
	 float xInput = 0;
	 if (Input::GetKeyDown(SDL_SCANCODE_A) || Input::GetKeyDown(SDL_SCANCODE_LEFT)) {
		xInput = -1;
	 }

	 if (Input::GetKeyDown(SDL_SCANCODE_D) || Input::GetKeyDown(SDL_SCANCODE_RIGHT)) {
		 xInput = 1;
	 }

	 if (Input::GetKeyDown(SDL_SCANCODE_SPACE)) {
		 std::cout << " SPACE pressed" << std::endl;

	 }
	 move(xInput);
	GameObject::Update();
	
}

 void PlayerController::move(float xInput) {
	 x += xInput * movementSpeed * Game::deltaTime;
	 
	 // substracting the actual width of texture since origin of the object is at top left
	 const float right_limit = Game::WIDTH - GameObject::textureWidth * GameObject::textureUpscale; 

	 if (x >= right_limit) { 
		 x = right_limit;
	 }
	 else if (x <= 0) {
		 x = 0;
	 }
 }
