#include "TestActor.h"
#include "raylib.h"
#include "Transform2D.h"



void TestActor::Destroy(Actor* actor)
{
}

void TestActor::Start()
{
}

void TestActor::Update()
{
	DrawRectangleV(Vector2() = { m_transform->GetLocalPosition().x, m_transform->GetLocalPosition().y }, 
		Vector2() = { m_transform->GetLocalScale().x, m_transform->GetLocalScale().y }, RED);
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
