
#include "Game.h"
const int WIDTH = 640, HEIGHT = 480;

Game *game = nullptr;

int main(int argc, char* argv[]) {
	
	game = new Game();
	game->init("MyEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, false);

	float deltaTime = 0;
	while(game->running()) {
		
		game->handleEvents();
		
		game->update(deltaTime);
		game->render();

	};

	game->clean();
	return 0;
}