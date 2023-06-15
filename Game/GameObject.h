#pragma once
#include "Game.h"
#include "SDL_image.h";
#include <vector>
class GameObject
{
public:
	GameObject(const char* name, const char* texturesheet, float x, float y, int textureWidth = 16, int textureHeight = 16, float textureUpscale = 1.0f);
	GameObject(const char* name, SDL_Texture* texture, float x, float y, int textureWidth = 16, int textureHeight = 16, float textureUpscale = 1.0f);

	~GameObject();

	virtual void Update();
	virtual void Render();

	static std::vector<GameObject*> gameobjects;
	static int lastId;
	static int RegisterGameObject(GameObject* go);
	static void DestroyGameObject(GameObject* go);
	static void UpdateEverything();
	static void RenderEverything();


	bool operator ==(GameObject* b) {
		return ID == b->ID;
	}
protected:
	float x, y;
	int textureWidth, textureHeight;
	int ID;
	float textureUpscale;
	char* name;

private:
	SDL_Texture* objectTexture;
	SDL_Rect srcRect, destRect;
	
};

