#include "Transform2D.h"
#include "Actor.h";

Transform2D::Transform2D(Actor owner) 
	: m_owner(owner), m_localMatrix(new Mat3), m_globalMatrix(new Mat3), m_localTranslation(new Mat3), m_localRotation(new Mat3), m_localScale(new Mat3)
{

}

Transform2D::~Transform2D()
{
	delete m_localMatrix;
	delete m_globalMatrix;
	delete m_localTranslation;
	delete m_localRotation;
	delete m_localScale;
	delete m_parent;
}

float Transform2D::GetGlobalRotationAngle()
{
	// atan2 a buncha stuff
	return 0.0f;
}

void Transform2D::SetLocalRotation(Mat3 rotation)
{
	*m_localRotation = rotation;
	//m_localRotationAngle = atan2 a buncha stuff
}

void Transform2D::SetLocalPosition(Vec2 position)
{
	m_localTranslation->m02 = position.x;
	m_localTranslation->m12 = position.y;
}

void Transform2D::SetLocalScale(Vec2 scale)
{
	m_localTranslation->m00 = scale.x;
	m_localTranslation->m11 = scale.y;
}

void Transform2D::Translate(Vec2 direction)
{
	SetLocalPosition(GetLocalPosition() + direction);
}

void Transform2D::Rotate(float radians)
{
	SetLocalRotation(GetLocalRotation() + Mat3::createRotation(radians));
}

void Transform2D::AddChild(Transform2D* child)
{
}

void Transform2D::RemoveChild(Transform2D* child)
{
}

void Transform2D::UpdateTransforms()
{
	*m_localMatrix = *m_localTranslation * *m_localRotation * *m_localScale;

	if (m_parent != nullptr)
		*m_globalMatrix = *m_parent->m_globalMatrix * *m_localMatrix;
	else
		*m_globalMatrix = *m_localMatrix;

	// update children down here (when they are real)
}
