#pragma once

#include "UIObject.h"

class ScreenUIObject : public UIObject
{
public:
	ScreenUIObject(std::wstring& dataAsset, BaseObject* parent = nullptr, float lifeTime = FLT_MAX);
	ScreenUIObject(Vector2 localPosition, std::wstring& dataAsset, BaseObject* parent = nullptr, float lifeTime = FLT_MAX);
	ScreenUIObject(Vector2 size, Vector2 localPosition, std::wstring& dataAsset, BaseObject* parent = nullptr, float lifeTime = FLT_MAX);

	~ScreenUIObject();
};

