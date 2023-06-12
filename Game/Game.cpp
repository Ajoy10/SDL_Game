#include "Game.h"

SDL_Texture* playerTexture;
SDL_Rect sourceRect, destRect;

int frame;

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

		SDL_Surface* tempSurface = IMG_Load("assets/player.png");
		playerTexture = SDL_CreateTextureFromSurface(renderer, tempSurface);
		SDL_FreeSurface(tempSurface);
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

void Game::update() {
	destRect.h = 64;
	destRect.w = 64;
	destRect.x = frame % 640;
	frame++;

}

void Game::render() {
	SDL_RenderClear(renderer);
	// Add your renderings here
	SDL_RenderCopy(renderer, playerTexture, NULL, &destRect);
	SDL_RenderPresent(renderer);
}

void Game::clean() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	std::cout << "Game cleaned!" << std::endl;
}
