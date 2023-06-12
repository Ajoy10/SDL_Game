#include "Game.h"
#include "GameObject.h"
#include "PlayerController.h"

PlayerController* playerObj;
GameObject* enemyObj;

Uint32 lastTicks;


int frame;


SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;
float Game::deltaTime;

Game::Game() {

}

Game::~Game() {
	
}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		lastTicks = SDL_GetTicks();
		std::cout << "SDL initialised!" << std::endl;
		int flags = 0;
		if (fullscreen) {
			flags = SDL_WINDOW_FULLSCREEN;
		}
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window) {
			std::cout << "Window created!" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 20, 20,20 , 255);
			std::cout << "Renderer created!" << std::endl;
		}

		isRunning = true;

		playerObj = new PlayerController("assets/player.png", 10, 200);
		enemyObj = new GameObject("assets/enemy_one.png", 10, 20);
	}
	else {
		isRunning = false;
	}
}

void Game::handleEvents() {
	
	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;

	default:
		break;
	}
}
bool done = false;
void Game::update(float delta) {
	// Wait until 16ms has elapsed since last frame
	while (!SDL_TICKS_PASSED(SDL_GetTicks(), lastTicks + 16))
		;
	deltaTime = (SDL_GetTicks() - lastTicks) / 1000.0f;
	// Clamp maximum delta time value
	if (deltaTime > 0.05f)
	{
		deltaTime = 0.05f;
	}

	playerObj->Update();
	enemyObj->Update();

	frame++;
	

}

void Game::render() {
	SDL_RenderClear(renderer);
	// Add your renderings here
	playerObj->Render();
	enemyObj->Render();

	SDL_RenderPresent(renderer);
	lastTicks = SDL_GetTicks();

}

void Game::clean() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	std::cout << "Game cleaned!" << std::endl;
}
