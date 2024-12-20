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

	// draw tank bottom
	DrawRectangleV(Vector2() = { GetTransform()->GetGlobalPosition().x, GetTransform()->GetGlobalPosition().y },
		Vector2() = { GetTransform()->GetGlobalScale().x * 50, GetTransform()->GetGlobalScale().y }, DARKGREEN);
}
