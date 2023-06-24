// GameObject.h
// compile with: /doc /LD
// post-build command: xdcmake GameObject.xdc

#pragma once
#include "Game.h"
#include "SDL_image.h";
#include "Collision.h"
#include <vector>

class GameObject
{
public:
	struct AnimationParams {
		short int animationIndex = 0;
		bool animationLoop = true;
		int animationDelay = 100;
		int animationFrames = 4;
		Uint32 animationStartTick;
	};

	struct GameObjectWithDelay {

		GameObject* go;
		Uint32 tickToDelete;
	};


	GameObject(const char* name, const char* texturesheet, float x, float y, int textureWidth = 16, int textureHeight = 16, float textureUpscale = 1.0f);
	GameObject(const char* name, SDL_Texture* texture, float x, float y, int textureWidth = 16, int textureHeight = 16, float textureUpscale = 1.0f);

	~GameObject();

	virtual void Update();
	virtual void Render();

	void CheckForCollision();

	void SetCollisionBox(int w, int h);
	void UpdateCollisionBox();
	
	/// <summary> Changes the animation index of an object
	/// <para>
	///		Can be used instead of swapping the animParams, for playing different animation.
	/// </para>
	///  </summary>
	void ChangeAnimation(short int index);

	/// <summary>  
	/// <title>Changes the current animation parameters to a new one</title>
	/// <para>
	///		Can be used instead of swapping the <c>animParams</c>, for playing different animation.
	/// </para>
	///  </summary>
	void ChangeAnimationParams(GameObject::AnimationParams newParams);

	char* name;


	static std::vector<GameObject*> gameobjects;
	static int lastId;
	static int RegisterGameObject(GameObject* go);
	static void DestroyGameObject(GameObject* go);
	static void DestroyGameObject(GameObject* go, int delay);

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
	bool hasCollision = false;
	bool animated = false;
	SDL_Rect collisionBox;
	virtual void Collided(GameObject* go);
	AnimationParams animParams;

private:
	SDL_Texture* objectTexture;
	SDL_Rect srcRect, destRect;

	static std::vector<GameObjectWithDelay> gameobjectsToDelete;
	
};

