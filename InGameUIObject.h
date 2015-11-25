#pragma once

#include "UIObject.h"

class InGameUIObject : public UIObject
{
public:
	InGameUIObject(std::wstring& dataAsset, BaseObject* parent = nullptr, float lifeTime = FLT_MAX);
	InGameUIObject(Vector2 localPosition, std::wstring& dataAsset, BaseObject* parent = nullptr, float lifeTime = FLT_MAX);
	InGameUIObject(Vector2 size, Vector2 localPosition, std::wstring& dataAsset, BaseObject* parent = nullptr, float lifeTime = FLT_MAX);

	~InGameUIObject();
};

