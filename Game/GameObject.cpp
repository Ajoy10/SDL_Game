#include "GameObject.h"

 std::vector<GameObject*> GameObject::gameobjects;
 int GameObject::lastId = 0;

GameObject::GameObject(const char* name, const char* texturesheet, float x, float y, int textureWidth, int textureHeight, float textureUpscale) {
	objectTexture = TextureManager::LoadTexture(texturesheet);
	this->name = (char*)name;
	this->x = x;
	this->y = y;
	this->textureWidth = textureWidth;
	this->textureHeight = textureHeight;
	this->textureUpscale = textureUpscale;
}

GameObject::GameObject(const char* name, SDL_Texture* texture, float x, float y, int textureWidth, int textureHeight, float textureUpscale) {
	objectTexture = texture;
	//std::cout << objectTexture << std::endl;
	this->name = (char*)name;
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

	if (hasCollision) {
		UpdateCollisionBox();
		CheckForCollision();
	}
}

void GameObject::CheckForCollision() {
	for (int i = 0; i < gameobjects.size(); i++) {
		if (gameobjects.at(i)->hasCollision && gameobjects.at(i) != this)  {
			//std::cout << name << " Collision check with " << gameobjects.at(i)->name << std::endl;

			if (Collision::AABB(collisionBox, gameobjects.at(i)->collisionBox)) {
				gameobjects.at(i)->Collided(this);
			}
		}
	}
}

void GameObject::SetCollisionBox( int w, int h)
{
	hasCollision = true;
	collisionBox.x = this->x;
	collisionBox.y = this->y;
	collisionBox.w = w;
	collisionBox.h = h;
}

void GameObject::UpdateCollisionBox()
{
	collisionBox.x = this->x;
	collisionBox.y = this->y;
}

void GameObject::Collided(GameObject* go)
{
	std::cout << name << " Collide with " << go->name << std::endl;
}

void GameObject::Render() {
	SDL_RenderCopy(Game::renderer, objectTexture, &srcRect, &destRect);
	if (hasCollision) {
		SDL_SetRenderDrawColor(Game::renderer, 255, 0, 0, 255);
		SDL_RenderDrawRect(Game::renderer, &collisionBox);
	}
}

int GameObject::RegisterGameObject(GameObject* go)
{
	go->ID = ++lastId;
	gameobjects.push_back(go);
	return go->ID;
}

void GameObject::DestroyGameObject(GameObject* go)
{
	gameobjects.erase(std::remove(gameobjects.begin(), gameobjects.end(), go), gameobjects.end());
	delete go;
}

void GameObject::UpdateEverything()
{
	for (int i = 0; i < gameobjects.size(); i++) {
		gameobjects.at(i)->Update();
	}
}


void GameObject::RenderEverything()
{
	for (int i = 0; i < gameobjects.size(); i++) {
		gameobjects.at(i)->Render();
	}
}

GameObject::~GameObject() {
	
}
