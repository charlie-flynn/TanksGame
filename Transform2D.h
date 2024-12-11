#pragma once
#include "Matrix3.h"
#include "Vector2.h"

typedef MathLibrary::Matrix3 Mat3;
typedef MathLibrary::Vector2 Vec2;

class Actor;

class Transform2D
{
public:
	Mat3 GetLocalRotation() { return *m_localRotation; }
	Vec2 GetLocalPosition() { return Vec2(m_localTranslation->m02, m_localTranslation->m12); }
	Vec2 GetLocalScale() { return Vec2(m_localScale->m00, m_localScale->m11); }
	float GetLocalRotationAngle() { return m_localRotationAngle; }
	float GetGlobalRotationAngle() { return m_globalRotationAngle; }

	void SetLocalRotation(Mat3 rotation);
	void SetLocalPosition(Vec2 position);
	void SetLocalScale(Vec2 scale);

	void Translate(Vec2 direction);
	void Rotate(float radians);

	void AddChild(Transform2D* child);
	void RemoveChild(Transform2D* child);

	void UpdateTransforms();
private:
	Mat3* m_localMatrix;
	Mat3* m_globalMatrix;

	Mat3* m_localTranslation;
	Mat3* m_localRotation;
	Mat3* m_localScale;
	float m_localRotationAngle;
	float m_globalRotationAngle;

	// if we have to destroy these it will be morally okay
	Transform2D* m_parent;
	Transform2D* m_children;

	Actor* m_owner;
};