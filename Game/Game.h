#pragma once
#include "SDL.h"
#include <iostream>
#include "TextureManager.h"
#include "Input.h"

class PlayerController;
class EnemyManager;


class Game
{
	public:
		Game();
		~Game();

		void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

		void handleEvents();
		void update();
		void render();
		void clean();

		static void GameOver();

		bool running() { return isRunning; }

		const static int WIDTH, HEIGHT;
		static SDL_Renderer* renderer;
		static SDL_Event event;
		static float deltaTime;
		
		static bool gamePaused;
		// Game specific data
		static PlayerController* player;
		static EnemyManager* enemyManager;

	private:
		bool isRunning;
		SDL_Window* window;
		
		
};

