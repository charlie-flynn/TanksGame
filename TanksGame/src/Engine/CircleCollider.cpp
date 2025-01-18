#include "CircleCollider.h"
#include "raylib.h"
#include "Actor.h"
#include "Transform2D.h"



void CircleCollider::Draw()
{
	DrawCircleLinesV({ GetOwner()->GetTransform()->GetGlobalPosition().x, GetOwner()->GetTransform()->GetGlobalPosition().y }, m_collisionRadius, RED);
}

bool CircleCollider::CheckCollisionCircle(CircleCollider* other)
{
	float distance = (GetOwner()->GetTransform()->GetGlobalPosition() - other->GetOwner()->GetTransform()->GetGlobalPosition()).getMagnitude();
	float sumRadii = GetCollisionRadius() + other->GetCollisionRadius();

    if (sumRadii >= distance)
    {
       SetCollidedActor(other->GetOwner());
        return true;
    }
    else
    {
        return false;
    }
}
