#include "TestActor.h"
#include "raylib.h"
#include "Transform2D.h"




TestActor::TestActor()
{

}

void TestActor::Destroy(Actor* actor)
{
}

void TestActor::Start()
{
}

void TestActor::Update()
{
	if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_LEFT)	)
		GetTransform()->Translate(Vec2(IsKeyDown(KEY_RIGHT) - IsKeyDown(KEY_LEFT), 0));
	if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_DOWN))
		GetTransform()->Translate(Vec2(0, IsKeyDown(KEY_DOWN) - IsKeyDown(KEY_UP)));

	DrawRectangleV(Vector2() = { GetTransform()->GetLocalPosition().x, GetTransform()->GetLocalPosition().y},
		Vector2() = { GetTransform()->GetLocalScale().x * 50, GetTransform()->GetLocalScale().y * 50 }, RED);
}

void TestActor::End()
{
}

void TestActor::OnCollision(Actor* other)
{
}

void TestActor::SetEnabled(const bool value)
{
}

void TestActor::OnEnable()
{
}

void TestActor::OnDisable()
{
}