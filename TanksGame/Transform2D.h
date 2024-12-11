#pragma once
#include "Matrix3.h"
#include "Vector2.h"

typedef MathLibrary::Matrix3 Mat3;
typedef MathLibrary::Vector2 Vec2;

class Actor;

class Transform2D
{
public:
	Transform2D(Actor owner);
	~Transform2D();

	Mat3 GetLocalRotation() { return *m_localRotation; }
	Vec2 GetLocalPosition() { return Vec2(m_localTranslation->m02, m_localTranslation->m12); }
	Vec2 GetLocalScale() { return Vec2(m_localScale->m00, m_localScale->m11); }
	float GetLocalRotationAngle() { return m_localRotationAngle; }
	float GetGlobalRotationAngle();

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

	// if we have to destroy these it will be morally okay
	// it'd really suck tho
	Transform2D* m_parent;
	// INSERT CHILDREN HERE (i dunno how to make a group of transform2d pointers)

	Actor& m_owner;
};