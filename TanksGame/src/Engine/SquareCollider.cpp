#include "SquareCollider.h"
#include "Actor.h"
#include "Transform2D.h"

void SquareCollider::Draw()
{
}

bool SquareCollider::CheckCollisionSquare(SquareCollider* other)
{
    Vec2 ownerPosition = GetOwner()->GetTransform()->GetGlobalPosition();
    Vec2 otherOwnerPosition = other->GetOwner()->GetTransform()->GetGlobalPosition();
    Vec2 otherDimensions = *other->GetDimensions();

    // AABB collision. if collided, return true. otherwise return false
    if (otherOwnerPosition.x < ownerPosition.y + dimensions->x &&
        otherOwnerPosition.x + otherDimensions.x > dimensions->x &&
        otherOwnerPosition.y < ownerPosition.y + dimensions->y &&
        otherOwnerPosition.y + otherDimensions.y > dimensions->y)
        return true;
        
    return false;
}
