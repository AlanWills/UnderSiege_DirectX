#pragma once

#include "BaseObject.h"

class GameObject : public BaseObject
{
public:
	GameObject(const char* dataAsset, BaseObject* parent = nullptr);
	GameObject(Vector2 localPosition, const char* dataAsset, BaseObject* parent = nullptr);
	GameObject(Vector2 size, Vector2 localPosition, const char* dataAsset, BaseObject* parent = nullptr);

	~GameObject();
};

