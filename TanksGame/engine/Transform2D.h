#pragma once
#include "Matrix3.h"
#include "Vector2.h"
#include "DynamicArray.h"

typedef MathLibrary::Matrix3 Mat3;
typedef MathLibrary::Vector2 Vec2;

class Actor;

class Transform2D
{
public:
	Transform2D(Actor& owner);
	~Transform2D();

	Mat3* GetLocalRotation() { return m_localRotation; }
	Vec2 GetLocalPosition() { return Vec2(m_localTranslation->m02, m_localTranslation->m12); }
	Vec2 GetGlobalPosition() { return Vec2(m_globalMatrix->m02, m_globalMatrix->m12); }
	Vec2 GetLocalScale() { return Vec2(m_localScale->m00, m_localScale->m11); }
	Vec2 GetGlobalScale();
	float GetLocalRotationAngle() { return m_localRotationAngle; }
	float GetGlobalRotationAngle();

	void SetLocalRotation(const Mat3& rotation);
	void SetLocalPosition(Vec2 position);
	void SetLocalScale(Vec2 scale);

	void Translate(Vec2 direction);
	void Rotate(float radians);

	DynamicArray<Transform2D*> GetChildren() { return m_children; };
	Transform2D* GetParent() { return m_parent; };
	void AddChild(Transform2D* child);
	bool RemoveChild(Transform2D* child);

	void UpdateTransforms();
private:
	Mat3* m_localMatrix;
	Mat3* m_globalMatrix;

	Mat3* m_localTranslation;
	Mat3* m_localRotation;
	Mat3* m_localScale;
	float m_localRotationAngle;


	Transform2D* m_parent;
	DynamicArray<Transform2D*> m_children;

	Actor& m_owner;
};