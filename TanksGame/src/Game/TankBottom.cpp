#include "TankBottom.h"
#include "raylib.h"
#include "Engine/Transform2D.h"
#include "Engine/SquareCollider.h"
#include "TankCannon.h"
#include "TankTreads.h"
#include <string>

TankBottom::TankBottom() : Actor("Tank")
{
	m_speed = 100.0f;
	m_gems = 0;

	Actor::Instantiate(new TankTreads(), this->GetTransform(), Vec2(25, 25), 0);
	Actor::Instantiate(new TankCannon(), this->GetTransform(), Vec2(25, 25), 0);
	AddComponent<SquareCollider>(m_collider = new SquareCollider(new Vec2(48, 48), this));
}

TankBottom::~TankBottom()
{
	Actor::~Actor();
	delete m_collider;
	m_collider = nullptr;
}

void TankBottom::Update(double deltaTime)
{
	// check for input
	// if there is input, move the player accounting for the speed value and deltaTime
	if (IsKeyDown(KEY_D) || IsKeyDown(KEY_A) || IsKeyDown(KEY_S) || IsKeyDown(KEY_W))
	{
		GetTransform()->Translate(Vec2(IsKeyDown(KEY_D) - IsKeyDown(KEY_A), 
			IsKeyDown(KEY_S) - IsKeyDown(KEY_W)).getNormalized() * m_speed * deltaTime);
	}

	// draw tank bottom
	DrawRectangleV(Vector2() = { GetTransform()->GetGlobalPosition().x, GetTransform()->GetGlobalPosition().y },
		Vector2() = { GetTransform()->GetGlobalScale().x * 50, GetTransform()->GetGlobalScale().y * 50 }, DARKGREEN);

	// draw gem counter
	DrawText(std::to_string(m_gems).c_str(), 10, 10, 20, BLUE);
}

void TankBottom::OnCollision()
{
	if (GetCollider()->GetCollidedActor()->GetName() == "Gem")
		m_gems++;
	else if (GetCollider()->GetCollidedActor()->GetName() == "Tile")
		GetTransform()->Translate((GetCollider()->GetCollidedActor()->GetTransform()->GetGlobalPosition() - GetTransform()->GetGlobalPosition()).getNormalized() * -2);
}
