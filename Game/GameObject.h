#pragma once
#include "Game.h"
class GameObject
{
public:
	GameObject(const char* texturesheet, int x, int y);
	~GameObject();

	void Update();
	void Render();
protected:
	int x, y;

private:
	SDL_Texture* objectTexture;
	SDL_Rect srcRect, destRect;
};

