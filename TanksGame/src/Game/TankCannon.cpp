#include "TankCannon.h"
#include "Engine/Actor.h"
#include "raylib.h"
#include "Engine/Transform2D.h"
#include <iostream>

void TankCannon::Update(double deltaTime)
{
	// shooty code
	if (m_fireRate <= 0)
	{
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
		{
			std::cout << "Pew!" << std::endl; // replace this line with shooting a projectile later
			m_fireRate = 0.5;
		}
	}
	else
	{
		m_fireRate -= deltaTime;
	}

	// rotate towards the mouse code
	Vec2 mousePosition = Vec2(GetMousePosition().x, GetMousePosition().y);
	Vec2 directionToMouseFromCannon = (mousePosition - GetTransform()->GetGlobalPosition()).getNormalized();

	if (Vec2::findAngle(GetTransform()->GetForwardVector(), directionToMouseFromCannon) < 0)
		GetTransform()->Rotate(0.0025f);
	else
		GetTransform()->Rotate(-0.0025f);

	// drawing code
	Rectangle rec = Rectangle();
	rec.height = 20;
	rec.width = 60;
	rec.x = GetTransform()->GetGlobalPosition().x;
	rec.y = GetTransform()->GetGlobalPosition().y;

	DrawRectanglePro(rec, { rec.width / 2 - 20, rec.height / 2 }, -GetTransform()->GetGlobalRotationAngle() * (180 / PI) , LIME);
}
