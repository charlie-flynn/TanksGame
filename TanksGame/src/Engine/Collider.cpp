#include "Collider.h"
#include "CircleCollider.h"
#include "SquareCollider.h"
#include "Actor.h"

Collider::~Collider()
{
    if (m_collidedActor != nullptr)
    {
        delete m_collidedActor;
        m_collidedActor = nullptr;
    }
}

bool Collider::CheckCollision(Actor* other)
{
    if (other->GetCollider() == nullptr)
        return false;

    if (this->isCircle && other->GetCollider()->isCircle)
        CheckCollisionCircle((CircleCollider*)other->GetCollider());

    if (this->isSquare && other->GetCollider()->isSquare)
        CheckCollisionSquare((SquareCollider*)other->GetCollider());


    return false;
}
