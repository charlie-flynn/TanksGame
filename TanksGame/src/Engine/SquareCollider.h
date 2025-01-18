#pragma once
#include "Collider.h"
#include "Vector2.h"

typedef MathLibrary::Vector2 Vec2;

class SquareCollider : public Collider
{
public:
	void Draw() override;
	bool CheckCollisionSquare(SquareCollider* other) override;

	Vec2* GetDimensions() { return dimensions; };
	void SetDimensions(float x, float y) { dimensions->x = x; dimensions->y = y; };
	void SetDimensions(Vec2* value) { *dimensions = *value; };
private:
	Vec2* dimensions;
};