#pragma once
#include "Game.h"
class GameObject
{
public:
	GameObject(const char* texturesheet, int x, int y);
	~GameObject();

	void Update();
	void Render();
private:
	int x, y;
	SDL_Texture* objectTexture;
	SDL_Rect srcRect, destRect;
};

