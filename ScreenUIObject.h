#pragma once

#include "UIObject.h"

class ScreenUIObject : public UIObject
{
public:
	ScreenUIObject(std::wstring& dataAsset, BaseObject* parent, float lifeTime);
	ScreenUIObject(Vector2 localPosition, std::wstring& dataAsset, BaseObject* parent, float lifeTime);
	ScreenUIObject(Vector2 size, Vector2 localPosition, std::wstring& dataAsset, BaseObject* parent, float lifeTime);

	~ScreenUIObject();
};

