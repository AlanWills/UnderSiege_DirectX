#include "pch.h"
#include "CircleCollider.h"
#include "BaseObject.h"


//-----------------------------------------------------------------------------------------------------------------------------------
CircleCollider::CircleCollider(BaseObject* parent) :
	Collider(parent)
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
CircleCollider::~CircleCollider()
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
void CircleCollider::UpdateColliderBounds()
{
	Vector2 parentWorldPos = m_parent->GetWorldPosition();
	float radius = std::max(m_parent->GetSize().x * 0.5f, m_parent->GetSize().y * 0.5f);

	m_boundingSphere.Center = Vector3(parentWorldPos.x, parentWorldPos.y, 0);
	m_boundingSphere.Radius = radius;
}


//-----------------------------------------------------------------------------------------------------------------------------------
bool CircleCollider::CheckCollisionWith(Vector2 point)
{
	ContainmentType containmentType = m_boundingSphere.Contains(point);
	return containmentType != ContainmentType::DISJOINT;
}