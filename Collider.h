#pragma once

#include "BaseObject.h"

class Collider
{
public:
	Collider(BaseObject* m_parent);
	~Collider();

	virtual bool CheckCollisionWith(Vector2 point) = 0;

protected:
	std::unique_ptr<BaseObject> m_parent;
};

