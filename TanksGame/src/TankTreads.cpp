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

	if (IsKeyDown(KEY_E))
		GetTransform()->Rotate(.1f);

	// draw the treads
	DrawRectanglePro(rec, { 0, 0 }, 4.51234, GRAY);

	std::cout << rec.x << ", " << rec.y << "\n";
}
