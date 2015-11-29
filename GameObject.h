#pragma once

#include "BaseObject.h"

class GameObject : public BaseObject
{
public:
	GameObject(const char* dataAsset, LoadType loadType = LoadType::kData, BaseObject* parent = nullptr);
	GameObject(Vector2 localPosition, const char* dataAsset, LoadType loadType = LoadType::kData, BaseObject* parent = nullptr);
	GameObject(Vector2 size, Vector2 localPosition, const char* dataAsset, LoadType loadType = LoadType::kData, BaseObject* parent = nullptr);

	~GameObject();
};

