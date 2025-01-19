#pragma once
#include "Collider.h"
#include "Vector2.h"

typedef MathLibrary::Vector2 Vec2;

class SquareCollider : public Collider
{
public:
	SquareCollider(Vec2* scale = new Vec2(10, 10), Actor* owner = nullptr) : Collider(owner) { m_colliderScale = scale; };
	void Draw() override;
	bool CheckCollisionSquare(SquareCollider* other) override;

	Vec2* GetDimensions() { return m_colliderScale; };
	void SetDimensions(float x, float y) { m_colliderScale->x = x; m_colliderScale->y = y; };
	void SetDimensions(Vec2* value) { *m_colliderScale = *value; };
private:
	Vec2* m_colliderScale;
};