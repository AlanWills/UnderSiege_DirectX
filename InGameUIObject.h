#pragma once

#include "UIObject.h"

class InGameUIObject : public UIObject
{
public:
	InGameUIObject(const char* dataAsset, LoadType loadType = LoadType::kData, BaseObject* parent = nullptr, float lifeTime = FLT_MAX);
	InGameUIObject(Vector2 localPosition, const char* dataAsset, LoadType loadType = LoadType::kData, BaseObject* parent = nullptr, float lifeTime = FLT_MAX);
	InGameUIObject(Vector2 size, Vector2 localPosition, const char* dataAsset, LoadType loadType = LoadType::kData, BaseObject* parent = nullptr, float lifeTime = FLT_MAX);

	~InGameUIObject();

	void HandleInput(DX::StepTimer const& timer) override;
};

