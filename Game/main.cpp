
#include "Game.h"
const int WIDTH = 640, HEIGHT = 480;

Game *game = nullptr;

int main(int argc, char* argv[]) {
	
	game = new Game();
	game->init("MyEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, false);
	Uint32 lastTicks = SDL_GetTicks();

	float deltaTime = 0;
	while(game->running()) {
		// Wait until 16ms has elapsed since last frame
		while (!SDL_TICKS_PASSED(SDL_GetTicks(), lastTicks + 16))
			;
		deltaTime = (SDL_GetTicks() - lastTicks )/1000.0f;
		// Clamp maximum delta time value
		if (deltaTime > 0.05f)
		{
			deltaTime = 0.05f;
		}
		game->handleEvents();
		
		game->update(deltaTime);
		game->render();
		lastTicks = SDL_GetTicks();

	};

	game->clean();
	return 0;
}