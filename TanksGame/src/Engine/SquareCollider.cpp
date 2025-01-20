#include "SquareCollider.h"
#include "Actor.h"
#include "Transform2D.h"
#include "raylib.h"

void SquareCollider::Draw()
{

    Vec2 ownerPosition = GetOwner()->GetTransform()->GetGlobalPosition();

    DrawRectangleLines(ownerPosition.x, ownerPosition.y, m_colliderScale->x, m_colliderScale->y, RED);
}

bool SquareCollider::CheckCollisionSquare(SquareCollider* other)
{
    Vec2 ownerPosition = GetOwner()->GetTransform()->GetGlobalPosition();
    Vec2 otherOwnerPosition = other->GetOwner()->GetTransform()->GetGlobalPosition();
    Vec2 otherDimensions = *other->GetDimensions();

    // AABB collision. if collided, return true. otherwise return false
    if (otherOwnerPosition.x < ownerPosition.x + m_colliderScale->x &&
        otherOwnerPosition.x + otherDimensions.x > ownerPosition.x &&
        otherOwnerPosition.y < ownerPosition.y + m_colliderScale->y &&
        otherOwnerPosition.y + otherDimensions.y > ownerPosition.y)
        return true;
        
    return false;
}
