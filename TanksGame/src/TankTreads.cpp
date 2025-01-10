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

	Vec2 forward = GetTransform()->GetForwardVector();
	float angle = Vec2::findAngle(forward, direction);

	// do weird math to check if its pointing the right way

	// if it is, do nothing
	// if it isn't, rotate towards that way

	if (angle > -3 && angle < 3)
	{
		if (angle < 0)
			GetTransform()->Rotate(.0025f);
		else
			GetTransform()->Rotate(-.0025f);
	}
}
