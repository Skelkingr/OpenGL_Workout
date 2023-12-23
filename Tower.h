#pragma once

#include "Actor.h"
#include "Game.h"
#include "MoveComponent.h"

class Tower : public Actor
{
public:
	Tower() = delete;
	Tower(Game* game);
	~Tower() override;

	void UpdateActor(float deltaTime) override;
private:
	MoveComponent* mMove;

	float mNextAttack;

	const float mAttacktime = 2.5f;
	const float mAttackRange = 100.0f;
};

