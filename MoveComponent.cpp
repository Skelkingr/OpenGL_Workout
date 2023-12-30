#include "MoveComponent.h"

MoveComponent::MoveComponent()
	:
	Component(),
	mAngularSpeed(0.0f),
	mForwardSpeed(0.0f)
{}

MoveComponent::MoveComponent(Actor* owner, int updateOrder)
	:
	Component(owner),
	mAngularSpeed(0.0f),
	mForwardSpeed(0.0f)
{}

void MoveComponent::Update(float deltaTime)
{
	if (!Math::NearZero(mAngularSpeed))
	{
		Quaternion rot = mOwner->GetRotation();
		float angle = mAngularSpeed * deltaTime;

		Quaternion inc(Vector3::UnitZ, angle);

		rot = Quaternion::Concatenate(rot, inc);
		mOwner->SetRotation(rot);
	}

	if (!Math::NearZero(mForwardSpeed))
	{
		Vector3 pos = mOwner->GetPosition();
		pos += mOwner->GetForward() * mForwardSpeed * deltaTime;
		mOwner->SetPosition(pos);
	}
}
