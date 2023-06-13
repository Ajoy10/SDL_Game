#include "GameObject.h"

GameObject::GameObject(const char* texturesheet, float x, float y, int textureWidth, int textureHeight, float textureUpscale) {
	objectTexture = TextureManager::LoadTexture(texturesheet);
	this->x = x;
	this->y = y;
	this->textureWidth = textureWidth;
	this->textureHeight = textureHeight;
	this->textureUpscale = textureUpscale;
}

void GameObject::Update() {
	

	srcRect.w = textureWidth;
	srcRect.h = textureHeight;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.w = srcRect.w * textureUpscale;
	destRect.h = srcRect.h * textureUpscale;
	destRect.x = x;
	destRect.y = y;
}

void GameObject::Render() {
	SDL_RenderCopy(Game::renderer, objectTexture, &srcRect, &destRect);
}

