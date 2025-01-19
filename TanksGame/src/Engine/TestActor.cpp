#include "TestActor.h"
#include "raylib.h"
#include "Engine/Transform2D.h"
#include "SquareCollider.h"




TestActor::TestActor()
{
	AddComponent<SquareCollider>(m_collider = new SquareCollider(new Vec2(12, 12), this));
}

void TestActor::Destroy(Actor* actor)
{
}

void TestActor::Start()
{
}

void TestActor::Update(double deltaTime)
{
	// movement code
	if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_LEFT)	)
		GetTransform()->Translate(Vec2((IsKeyDown(KEY_RIGHT) - IsKeyDown(KEY_LEFT)) * 0.15f, 0));
	if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_DOWN))
		GetTransform()->Translate(Vec2(0, (IsKeyDown(KEY_DOWN) - IsKeyDown(KEY_UP)) * 0.15f));

	// draw the actor
	DrawRectangleV(Vector2() = { GetTransform()->GetGlobalPosition().x, GetTransform()->GetGlobalPosition().y},
		Vector2() = { GetTransform()->GetGlobalScale().x * 50, GetTransform()->GetGlobalScale().y * 50 }, RED);

	m_collider->Draw();
}

void TestActor::End()
{
}

void TestActor::OnCollision(Actor* other)
{
	DrawRectangleV({ 30, 30 }, { 30, 30 }, GREEN);
}

void TestActor::OnEnable()
{
}

void TestActor::OnDisable()
{
}
