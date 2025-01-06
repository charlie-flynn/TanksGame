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

	std::cout << IsKeyDown(KEY_RIGHT) - IsKeyDown(KEY_LEFT) << ", " << IsKeyDown(KEY_DOWN) - IsKeyDown(KEY_UP) << "\n";
	// draw the treads
	DrawRectanglePro(rec, { rec.width / 2, rec.height / 2 }, GetTransform()->GetGlobalRotationAngle() * (180 / PI) + 90, GRAY);
}

void TankTreads::RotateToDirection(Vec2 direction)
{
	if (direction == Vec2(0, 0))
		return;

	Vec2 forward = GetTransform()->GetForwardVector();

	// do weird math to check if its pointing the right way

	// if it is, do nothing
	// if it isn't, rotate towards that way

	if (!(forward == direction))
	{
		if (Vec2::findAngle(forward, direction) < -Vec2::findAngle(forward, direction))
			GetTransform()->Rotate(.001f);
		else if (Vec2::findAngle(direction, forward) < -Vec2::findAngle(forward, direction))
			GetTransform()->Rotate(-.001f);
	}
}
