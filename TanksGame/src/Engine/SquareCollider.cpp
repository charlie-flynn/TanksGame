#include "SquareCollider.h"
#include "Actor.h"
#include "Transform2D.h"
#include "raylib.h"

void SquareCollider::Draw()
{

    Vec2 ownerPosition = GetOwner()->GetTransform()->GetGlobalPosition();

    Rectangle rectangle = Rectangle();
    rectangle.width = m_colliderScale->x;
    rectangle.height = m_colliderScale->y;
    rectangle.x = ownerPosition.x;
    rectangle.y = ownerPosition.y;


    DrawRectangleLinesEx(rectangle, 3, RED);
}

bool SquareCollider::CheckCollisionSquare(SquareCollider* other)
{
    Vec2 ownerPosition = GetOwner()->GetTransform()->GetGlobalPosition();
    Vec2 otherOwnerPosition = other->GetOwner()->GetTransform()->GetGlobalPosition();
    Vec2 otherDimensions = *other->GetDimensions();

    // AABB collision. if collided, return true. otherwise return false
    if (otherOwnerPosition.x < ownerPosition.y + m_colliderScale->x &&
        otherOwnerPosition.x + otherDimensions.x > m_colliderScale->x &&
        otherOwnerPosition.y < ownerPosition.y + m_colliderScale->y &&
        otherOwnerPosition.y + otherDimensions.y > m_colliderScale->y)
        return true;
        
    return false;
}
