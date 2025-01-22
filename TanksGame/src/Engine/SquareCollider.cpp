#include "SquareCollider.h"
#include "Actor.h"
#include "Transform2D.h"
#include "raylib.h"

SquareCollider::SquareCollider()
{
    isSquare = true;
}

SquareCollider::~SquareCollider()
{
    delete m_colliderScale;
}

void SquareCollider::Draw()
{

    Vec2 ownerPosition = GetOwner()->GetTransform()->GetGlobalPosition();

    DrawRectangleLines(ownerPosition.x + m_colliderOffset->x, ownerPosition.y + m_colliderOffset->y, m_colliderScale->x, m_colliderScale->y, RED);
}

bool SquareCollider::CheckCollisionSquare(SquareCollider* other)
{
    Vec2 ownerPosition = GetOwner()->GetTransform()->GetGlobalPosition();
    Vec2 otherOwnerPosition = other->GetOwner()->GetTransform()->GetGlobalPosition();
    Vec2 otherDimensions = *other->GetDimensions();
    Vec2 otherOffset = *other->GetOffset();

    // AABB collision. if collided, return true. otherwise return false
    if (otherOwnerPosition.x + otherOffset.x < ownerPosition.x + m_colliderOffset->x + m_colliderScale->x &&
        otherOwnerPosition.x + otherOffset.x + otherDimensions.x > m_colliderOffset->x + ownerPosition.x &&
        otherOwnerPosition.y + otherOffset.y < ownerPosition.y + m_colliderOffset->y + m_colliderScale->y &&
        otherOwnerPosition.y + otherOffset.y + otherDimensions.y > m_colliderOffset->y + ownerPosition.y)
    {
        SetCollidedActor(other->GetOwner());
        other->SetCollidedActor(GetOwner());
        return true;
    }
        
    return false;
}
