#pragma once

#include "Collider.h"

class CircleCollider : public Collider
{
public:
	CircleCollider(BaseObject* parent);
	~CircleCollider();

	bool CheckCollisionWith(Vector2 point) override;

private:
	void UpdateColliderBounds();

	BoundingSphere m_boundingSphere;
};

