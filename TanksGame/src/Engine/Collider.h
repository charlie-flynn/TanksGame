#pragma once
#include "Component.h"

class CircleCollider;
class SquareCollider;

class Collider : public Component
{
public:
	~Collider();
	Actor* GetCollidedActor() { return m_collidedActor; };
	bool CheckCollision(Actor* other);
	virtual void Draw() {};
	virtual bool CheckCollisionCircle(CircleCollider* other) { return false; };
	virtual bool CheckCollisionSquare(SquareCollider* other) { return false; };
protected:
	void SetCollidedActor(Actor* actor) { m_collidedActor = actor; };
private:
	Actor* m_collidedActor;
};