#pragma once
#include "Collider.h"
#include "Vector2.h"

typedef MathLibrary::Vector2 Vec2;

class SquareCollider : public Collider
{
public:
	SquareCollider(Vec2* scale = new Vec2(10, 10), Actor* owner = nullptr, Vec2* offset = new Vec2(0, 0));
	~SquareCollider();

	void Draw() override;
	bool CheckCollisionSquare(SquareCollider* other) override;

	Vec2* GetDimensions() { return m_colliderScale; };
	Vec2* GetOffset() { return m_colliderOffset; };
	void SetDimensions(float x, float y) { m_colliderScale->x = x; m_colliderScale->y = y; };
	void SetDimensions(Vec2* value) { *m_colliderScale = *value; };
private:
	Vec2* m_colliderScale;
	Vec2* m_colliderOffset;
};