#pragma once

#include "UIObject.h"

class ScreenUIObject : public UIObject
{
public:
	ScreenUIObject(const char* dataAsset, BaseObject* parent = nullptr, float lifeTime = FLT_MAX);
	ScreenUIObject(Vector2 localPosition, const char* dataAsset, BaseObject* parent = nullptr, float lifeTime = FLT_MAX);
	ScreenUIObject(Vector2 size, Vector2 localPosition, const char* dataAsset, BaseObject* parent = nullptr, float lifeTime = FLT_MAX);

	~ScreenUIObject();
};

