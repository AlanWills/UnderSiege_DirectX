#pragma once

#include "BaseObject.h"

class GameObject : BaseObject
{
public:
	GameObject(std::wstring& dataAsset, BaseObject* parent = nullptr);
	GameObject(Vector2 localPosition, std::wstring& dataAsset, BaseObject* parent = nullptr);
	GameObject(Vector2 size, Vector2 localPosition, std::wstring& dataAsset, BaseObject* parent = nullptr);

	~GameObject();
};

