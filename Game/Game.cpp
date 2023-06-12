#include "Game.h"
#include "GameObject.h"

GameObject* playerObj;
GameObject* enemyObj;

int frame;


SDL_Renderer* Game::renderer = nullptr;

Game::Game() {

}

Game::~Game() {
	
}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
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

		playerObj = new GameObject("assets/player.png", 10, 200);
		enemyObj = new GameObject("assets/enemy_one.png", 10, 20);
	}
	else {
		isRunning = false;
	}
}

void Game::handleEvents() {
	SDL_Event event;
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
}

void Game::clean() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	std::cout << "Game cleaned!" << std::endl;
}
