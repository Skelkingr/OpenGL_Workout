#pragma once

#include <vector>

#include "Component.h"
#include "Game.h"
#include "Math.h"

class Actor
{
public:
	enum State
	{
		EActive,
		EPaused,
		EDead
	};
public:
	Actor(Game* game);
	virtual ~Actor();

	void Update(float deltaTime);
	void UpdateComponents(float deltaTime);
	virtual void UpdateActor(float deltaTime) = 0;

	Game* GetGame() const { return this->mGame; }
	Vector2 GetPosition() const { return this->mPosition; }
	float GetRotation() const { return this->mRotation; }
	float GetScale() const { return this->mScale; }
	int GetState() const { return this->mState; }

	void SetPosition(Vector2 position) { this->mPosition = position; }
	void SetScale(float scale) { this->mScale = scale; }

	void AddComponent(Component* component);
	void RemoveComponent(Component* component);
private:
	State mState;
	Vector2 mPosition;
	float mScale;
	float mRotation;
	std::vector<Component*> mComponents;
	Game* mGame;
};
