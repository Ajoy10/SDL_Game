#pragma once
#include "Game.h"
class GameObject
{
public:
	GameObject(const char* texturesheet, SDL_Renderer *renderer, int x, int y);
	~GameObject();

	void Update();
	void Render();
private:
	SDL_Renderer* renderer;
	int x, y;
	SDL_Texture* objectTexture;
	SDL_Rect srcRect, destRect;
};

