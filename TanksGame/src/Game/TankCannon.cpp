#include "TankCannon.h"
#include "Engine/Actor.h"
#include "raylib.h"
#include "Engine/Transform2D.h"
#include "Bullet.h"

void TankCannon::Update(double deltaTime)
{
	// shooty code
	if (m_fireRate <= 0)
	{
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
		{
			Actor::Instantiate(new Bullet(), nullptr, GetTransform()->GetGlobalPosition(), GetTransform()->GetGlobalRotationAngle());
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

	if (Vec2::findAngle(GetTransform()->GetForwardVector(), directionToMouseFromCannon) < -0.2)
		GetTransform()->Rotate(0.20f);
	else if (Vec2::findAngle(GetTransform()->GetForwardVector(), directionToMouseFromCannon) > 0.2)
		GetTransform()->Rotate(-0.20f);

	// drawing code
	Rectangle rec = Rectangle();
	rec.height = 20;
	rec.width = 60;
	rec.x = GetTransform()->GetGlobalPosition().x;
	rec.y = GetTransform()->GetGlobalPosition().y;

	DrawRectanglePro(rec, { rec.width / 2 - 20, rec.height / 2 }, -GetTransform()->GetGlobalRotationAngle() * (180 / PI) , LIME);
}
