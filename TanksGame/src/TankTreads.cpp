#include "TankTreads.h"
#include "raylib.h"
#include "../engine/Transform2D.h"
#include <iostream>

void TankTreads::Update(double deltaTime)
{
	// check for input and rotate in that direction accordingly


	Rectangle rec = Rectangle();
	rec.height = 40;
	rec.width = 70;
	rec.x = GetTransform()->GetGlobalPosition().x;
	rec.y = GetTransform()->GetGlobalPosition().y;

	RotateToDirection(Vec2(IsKeyDown(KEY_RIGHT) - IsKeyDown(KEY_LEFT),
		IsKeyDown(KEY_DOWN) - IsKeyDown(KEY_UP)).getNormalized());

	// draw the treads
	DrawRectanglePro(rec, { rec.width / 2, rec.height / 2 }, GetTransform()->GetGlobalRotationAngle() * (180 / PI) + 90, GRAY);
}

void TankTreads::RotateToDirection(Vec2 direction)
{
	if (direction == Vec2(0, 0))
		return;

	// if the direction isnt a cardinal direction, invert the x so it looks right
	if (direction.x != 0 && direction.y != 0)
	{
		direction.x *= -1;
		// if it is very specifically this direction, pretend its the opposite of that
		if (abs(direction.x - -0.707107f) < 0.01f && abs(direction.y - 0.707107f) < 0.01f)
			direction = Vec2(0.707107f, -0.707107f);
	}

	Vec2 forward = GetTransform()->GetForwardVector();
	Vec2 absoluteDirection = Vec2(abs(direction.x), abs(direction.y));

	float fowardDirectionAngle = Vec2::findAngle(forward, direction);
	float forwardAbsDirectionAngle = Vec2::findAngle(forward, absoluteDirection);

	if (Vec2(direction.x * -1, direction.y * -1) == absoluteDirection)
	{
		// run the usual checks but with ForwardAbsDirectionAngle

		if (forwardAbsDirectionAngle > 0)
			GetTransform()->Rotate(0.0050f);
		else
			GetTransform()->Rotate(-0.0050f);
	}
	else
	{
		if (fowardDirectionAngle > 0)
			GetTransform()->Rotate(0.0050f);
		else
			GetTransform()->Rotate(-0.0050f);
	}

}
