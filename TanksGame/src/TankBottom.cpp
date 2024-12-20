#include "TankBottom.h"
#include "raylib.h"
#include "../engine/Transform2D.h"

TankBottom::TankBottom()
{
	m_speed = 50.0f;
}

void TankBottom::Update(double deltaTime)
{
	// check for input
	// if there is input, move the player accounting for the speed value and deltaTime
	if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_UP) || IsKeyDown(KEY_DOWN))
		GetTransform()->Translate(Vec2(IsKeyDown(KEY_RIGHT) - IsKeyDown(KEY_LEFT), 
			IsKeyDown(KEY_DOWN) - IsKeyDown(KEY_UP)).getNormalized() * m_speed * deltaTime);

	// draw tank bottom
	DrawRectangleV(Vector2() = { GetTransform()->GetGlobalPosition().x, GetTransform()->GetGlobalPosition().y },
		Vector2() = { GetTransform()->GetGlobalScale().x * 50, GetTransform()->GetGlobalScale().y * 50 }, DARKGREEN);
}
