#pragma once
#include "Game.h"
class GameObject
{
public:
	GameObject(const char* texturesheet, float x, float y, int textureWidth = 16, int textureHeight = 16, float textureUpscale = 1.0f);
	~GameObject();

	void Update();
	void Render();
protected:
	float x, y;
	int textureWidth, textureHeight;
	float textureUpscale;

private:
	SDL_Texture* objectTexture;
	SDL_Rect srcRect, destRect;
	
};

