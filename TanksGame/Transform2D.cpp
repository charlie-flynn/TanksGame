#include "Transform2D.h"
#include "Actor.h"
#include <cmath>
#include <iostream>

Transform2D::Transform2D(Actor& owner) 
	: m_owner(owner)
{
	m_parent = nullptr;
	m_localRotationAngle = 0;
	m_localMatrix = new Mat3(1, 0, 0, 0, 1, 0, 0, 0, 1);
	m_globalMatrix = new Mat3(1, 0, 0, 0, 1, 0, 0, 0, 1);
	m_localTranslation = new Mat3(1, 0, 0, 0, 1, 0, 0, 0, 1);
	m_localRotation = new Mat3(1, 0, 0, 0, 1, 0, 0, 0, 1);
	m_localScale = new Mat3(1, 0, 0, 0, 1, 0, 0, 0, 1);
}

Transform2D::~Transform2D()
{
	delete m_localMatrix;
	delete m_globalMatrix;
	delete m_localTranslation;
	delete m_localRotation;
	delete m_localScale;
	if (m_parent)
		delete m_parent;
}

float Transform2D::GetGlobalRotationAngle()
{
	return (float)atan2(m_globalMatrix->m01, m_globalMatrix->m00);
}

void Transform2D::SetLocalRotation(const Mat3& rotation)
{
	*m_localRotation = rotation;
	m_localRotationAngle = -(float)atan2(m_localRotation->m01, m_localRotation->m00);
}

void Transform2D::SetLocalPosition(const Vec2 position)
{
	m_localTranslation->m02 = position.x;
	m_localTranslation->m12 = position.y;
}

void Transform2D::SetLocalScale(const Vec2 scale)
{
	m_localTranslation->m00 = scale.x;
	m_localTranslation->m11 = scale.y;
}

void Transform2D::Translate(const Vec2 direction)
{
	SetLocalPosition(GetLocalPosition() + direction);
}

void Transform2D::Rotate(const float radians)
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
