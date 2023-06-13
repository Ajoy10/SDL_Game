#pragma once
#include "Game.h"
class GameObject
{
public:
	GameObject(const char* texturesheet, float x, float y);
	~GameObject();

	void Update();
	void Render();
protected:
	float x, y;

private:
	SDL_Texture* objectTexture;
	SDL_Rect srcRect, destRect;
};

