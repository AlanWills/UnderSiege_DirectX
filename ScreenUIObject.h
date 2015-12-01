#pragma once

#include "UIObject.h"

class ScreenUIObject : public UIObject
{
public:
	ScreenUIObject(const char* dataAsset, LoadType loadType = LoadType::kData, BaseObject* parent = nullptr, float lifeTime = FLT_MAX);
	ScreenUIObject(Vector2 localPosition, const char* dataAsset, LoadType loadType = LoadType::kData, BaseObject* parent = nullptr, float lifeTime = FLT_MAX);
	ScreenUIObject(Vector2 size, Vector2 localPosition, const char* dataAsset, LoadType loadType = LoadType::kData, BaseObject* parent = nullptr, float lifeTime = FLT_MAX);

	~ScreenUIObject();

	void HandleInput(DX::StepTimer const& timer) override;
};