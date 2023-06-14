#pragma once
#include "GameObject.h"
#include "TextureManager.h"

class Bullet : public GameObject {
private:
	float xDelta, yDelta;
	static SDL_Texture* bulletTexture;
public:
	Bullet(float x, float y, float xDelta, float yDelta);
	void Update();
	static SDL_Texture* GetBulletTexture();

};

