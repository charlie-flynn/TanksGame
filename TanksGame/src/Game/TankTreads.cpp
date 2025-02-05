#include "TankTreads.h"
#include "../engine/Transform2D.h"
#include "raylib.h"
#include <cmath>

void TankTreads::Update(double deltaTime)
{
	// check for input and rotate in that direction accordingly



	RotateToDirection(Vec2(IsKeyDown(KEY_D) - IsKeyDown(KEY_A),
		IsKeyDown(KEY_S) - IsKeyDown(KEY_W)).getNormalized());

	// draw the treads
	Rectangle rec = Rectangle();
	rec.height = 40;
	rec.width = 70;
	rec.x = GetTransform()->GetGlobalPosition().x;
	rec.y = GetTransform()->GetGlobalPosition().y;

	DrawRectanglePro(rec, { rec.width / 2, rec.height / 2 }, GetTransform()->GetGlobalRotationAngle() * (180 / PI) + 90, GRAY);
}

void TankTreads::RotateToDirection(Vec2 direction)
{
	if (direction == Vec2(0, 0))
		return;

	// if the direction isnt a cardinal direction, invert the x so it looks right with the tank treads
	if (direction.x != 0 && direction.y != 0)
	{
		direction.x *= -1;

		// if the direction is very specifically (0.707107, -0.707107), pretend its the opposite of that
		if (abs(direction.x - 0.707107f) < 0.01f && abs(direction.y - -0.707107f) < 0.01f)
			direction = Vec2(-0.707107f, 0.707107f);
	}

	Vec2 forward = GetTransform()->GetForwardVector();
	Vec2 absoluteDirection = Vec2(abs(direction.x), abs(direction.y));

	// if the inverse of the direction is equal to the absolute value of the direction, use the angle from the absolute value of the direction
	// otherwise, use the direction itself
	if (Vec2(direction.x * -1, direction.y * -1) == absoluteDirection)
	{
		float forwardAbsDirectionAngle = Vec2::findAngle(forward, absoluteDirection);
		if (forwardAbsDirectionAngle > 0.2f)
			GetTransform()->Rotate(0.20f);
		else if (forwardAbsDirectionAngle < -0.2f)
			GetTransform()->Rotate(-0.20f);
	}
	else
	{
		float forwardDirectionAngle = Vec2::findAngle(forward, direction);
		if (forwardDirectionAngle > 0.2f)
			GetTransform()->Rotate(0.10f);
		else if (forwardDirectionAngle < -0.2f)
			GetTransform()->Rotate(-0.10f);
	}

}
