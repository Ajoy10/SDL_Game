#pragma once
#include "SDL.h"
#include <iostream>
#include "TextureManager.h"

class Game
{
	public:
		Game();
		~Game();

		void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

		void handleEvents();
		void update(float delta);
		void render();
		void clean();

		bool running() { return isRunning; }

		static SDL_Renderer* renderer;
	private:
		bool isRunning;
		SDL_Window* window;
};

