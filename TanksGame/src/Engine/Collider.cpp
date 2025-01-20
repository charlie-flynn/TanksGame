#include "Collider.h"
#include "CircleCollider.h"
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
    return false;
}
