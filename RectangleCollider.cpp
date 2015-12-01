#include "pch.h"
#include "RectangleCollider.h"
#include "BaseObject.h"


//-----------------------------------------------------------------------------------------------------------------------------------
RectangleCollider::RectangleCollider(BaseObject* parent) :
	Collider(parent)
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
RectangleCollider::~RectangleCollider()
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
void RectangleCollider::UpdateColliderBounds()
{
	Vector2 parentWorldPos = m_parent->GetWorldPosition();
	float parentWorldRot = m_parent->GetWorldRotation();

	m_boundingBox.Center = Vector3(parentWorldPos.x, parentWorldPos.y, 0); 
	m_boundingBox.Extents = Vector3(m_parent->m_size.x * 0.5f, m_parent->m_size.y * 0.5f, 0.001f);
	m_boundingBox.Orientation = Quaternion::CreateFromRotationMatrix(Matrix::CreateRotationZ(parentWorldRot));

	// May need to use this instead
	//m_boundingBox.Transform(m_boundingBox, 1, Vector3(parentWorldRot), Vector3(parentWorldPos.x, parentWorldPos.y, 0));
}


//-----------------------------------------------------------------------------------------------------------------------------------
bool RectangleCollider::CheckCollisionWith(Vector2 point)
{
	UpdateColliderBounds();

	ContainmentType containmentType = m_boundingBox.Contains(point);
	return containmentType != ContainmentType::DISJOINT;
}