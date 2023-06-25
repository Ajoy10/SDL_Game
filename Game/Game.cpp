#pragma once
#include "Game.h"
#include "PlayerController.h"
#include "EnemyManager.h"

Uint32 lastTicks;


int frame;

const int Game::WIDTH = 820;
const int Game::HEIGHT = 640;

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;
float Game::deltaTime;

PlayerController* Game::player;
EnemyManager* Game::enemyManager;


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

		player = new PlayerController("assets/player_anim.png", Game::WIDTH/2, Game::HEIGHT - 200);
		
		enemyManager = new EnemyManager(30);
		enemyManager->Init();
	}
	else {
		isRunning = false;
	}
}

void Game::handleEvents() {
	Input::SetKeystate();

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
void Game::update() {
	// Wait until 2ms has elapsed since last frame
	while (!SDL_TICKS_PASSED(SDL_GetTicks(), lastTicks + 2))
		;
	deltaTime = (SDL_GetTicks() - lastTicks)/1000.0f;
	lastTicks = SDL_GetTicks();
	//std::cout << "Delta: " << deltaTime << std::endl;
	// Clamp maximum delta time value
	if (deltaTime > 0.05f)
	{
		deltaTime = 0.05f;
	}


	// playerObj->Update();
	/*enemyObj1->Update();
	enemyObj2->Update();*/
	//enemyManager->Update();

	GameObject::UpdateEverything();

	frame++;
	

}

void Game::render() {
	SDL_SetRenderDrawColor(renderer, 20, 20, 20, 255);
	SDL_RenderClear(renderer);
	// Add your renderings here
	//playerObj->Render();
	/*enemyObj1->Render();
	enemyObj2->Render();*/
	//enemyManager->Render();

	GameObject::RenderEverything();

	SDL_RenderPresent(renderer);


}

void Game::clean() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	std::cout << "Game cleaned!" << std::endl;
}
