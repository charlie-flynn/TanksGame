#include "Transform2D.h"
#include "Actor.h"
#include <cmath>

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
	if (m_parent != nullptr)
		delete m_parent;
}

Vec2 Transform2D::GetGlobalScale()
{
	Vec2 xAxis = Vec2(m_globalMatrix->m00, m_globalMatrix->m10);
	Vec2 yAxis = Vec2(m_globalMatrix->m01, m_globalMatrix->m11);
	return Vec2(xAxis.getMagnitude(), yAxis.getMagnitude());
}

float Transform2D::GetGlobalRotationAngle()
{
	return (float)atan2(m_globalMatrix->m01, m_globalMatrix->m00);
}

void Transform2D::SetLocalRotation(const Mat3& rotation)
{
	*m_localRotation = rotation;
	m_localRotationAngle = (float)atan2(m_localRotation->m01, m_localRotation->m00);
	UpdateTransforms();
}

void Transform2D::SetLocalPosition(const Vec2 position)
{
	m_localTranslation->m02 = position.x;
	m_localTranslation->m12 = position.y;
	UpdateTransforms();
}

void Transform2D::SetLocalScale(const Vec2 scale)
{
	m_localTranslation->m00 = scale.x;
	m_localTranslation->m11 = scale.y;
	UpdateTransforms();
}

void Transform2D::Translate(const Vec2 direction)
{
	SetLocalPosition(GetLocalPosition() + direction);
}

void Transform2D::Rotate(const float radians)
{
	SetLocalRotation(Mat3::createRotation(m_localRotationAngle + radians));
}

void Transform2D::AddChild(Transform2D* child)
{
	if (child == m_parent || child == this)
		return;

	m_children.Add(child);

	child->m_parent = this;
	child->UpdateTransforms();
}

bool Transform2D::RemoveChild(Transform2D* child)
{
	int oldLength = m_children.Length();

	if (m_children.Length() == 0)
		return false;

	m_children.Remove(child);

	if (m_children.Length() == oldLength)
	{

		return false;
	}
	else
	{
		child->m_parent = nullptr;
		return true;
	}

}

void Transform2D::UpdateTransforms()
{
	*m_localMatrix = *m_localTranslation * *m_localRotation * *m_localScale;

	if (m_parent != nullptr)
		*m_globalMatrix = *m_parent->m_globalMatrix * *m_localMatrix;
	else
		*m_globalMatrix = *m_localMatrix;

	// update children
	for (int i = 0; i < m_children.Length(); i++)
	{
		m_children[i]->UpdateTransforms();
	}

}
