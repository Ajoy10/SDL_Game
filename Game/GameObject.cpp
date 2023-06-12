#include "GameObject.h"

GameObject::GameObject(const char* texturesheet, int x, int y) {
	objectTexture = TextureManager::LoadTexture(texturesheet);
	this->x = x;
	this->y = y;
}

void GameObject::Update() {
	

	srcRect.w = 16;
	srcRect.h = 16;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.w = srcRect.w * 2;
	destRect.h = srcRect.h * 2;
	destRect.x = x;
	destRect.y = y;
}

void GameObject::Render() {
	SDL_RenderCopy(Game::renderer, objectTexture, &srcRect, &destRect);
}

