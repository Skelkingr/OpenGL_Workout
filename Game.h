#pragma once

#include "Shader.h"
#include "Texture.h"
#include "VertexArray.h"

#include <SDL.h>

#include <string>
#include <unordered_map>
#include <vector>

constexpr int CLIENT_WIDTH = 1024;
constexpr int CLIENT_HEIGHT = 768;

class Game
{
public:
	Game();

	bool Initialize();
	void RunLoop();
	void Shutdown();

	void AddActor(class Actor* actor);
	void RemoveActor(class Actor* actor);

	void AddSprite(class SpriteComponent* sprite);
	void RemoveSprite(class SpriteComponent* sprite);

	Texture* GetTexture(const std::string& fileName);
private:
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();

	bool LoadShaders();
	void CreateSpriteVerts();

	void LoadData();
	void UnloadData();
private:
	std::unordered_map<std::string, Texture*> mTextures;
	std::vector<class Actor*> mActors;
	std::vector<class Actor*> mPendingActors;
	std::vector<class SpriteComponent*> mSprites;

	Shader* mSpriteShader;
	VertexArray* mSpriteVerts;
	
	SDL_Window* mWindow;
	SDL_GLContext mContext;

	Uint32 mTicksCount;
	bool mIsRunning;
	bool mUpdatingActors;
};