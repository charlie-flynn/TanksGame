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
	DrawRectanglePro(rec, { rec.width / 2, rec.height / 2 }, GetTransform()->GetGlobalRotationAngle() * (180 / PI), GRAY);
}

void TankTreads::RotateToDirection(Vec2 direction)
{
	if (direction == Vec2(0, 0))
		return;

	// if the direction isnt a cardinal direction, invert the x so it looks right
	if (direction.x != 0 && direction.y != 0)
		direction.x *= -1;

	Vec2 forward = GetTransform()->GetForwardVector();
	Vec2 behind = forward * -1;
	float angleForward = Vec2::findAngle(forward, direction);
	float angleBehind = Vec2::findAngle(behind, direction);

	DrawLine(10, 10, 10.0f * angleForward, 10, BLUE);
	DrawLine(10, 20, 10.0f * angleBehind, 20, GREEN);

	if (abs(angleForward) < abs(angleBehind))
	{
		GetTransform()->Rotate(0.0025f);
		DrawPoly({ 10, 10 }, 4, 10, 0, RED);
	}
	else
		GetTransform()->Rotate(-0.0025f);

}
