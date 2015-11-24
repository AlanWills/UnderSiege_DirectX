#pragma once

#include "BaseObject.h"

class UIObject : public BaseObject
{
public:
	UIObject(std::wstring& dataAsset, BaseObject* parent, float lifeTime = FLT_MAX);
	UIObject(Vector2 localPosition, std::wstring& dataAsset, BaseObject* parent, float lifeTime = FLT_MAX);
	UIObject(Vector2 size, Vector2 localPosition, std::wstring& dataAsset, BaseObject* parent, float lifeTime = FLT_MAX);

	void Update(DX::StepTimer const& timer) override;
	void Draw(SpriteBatch* spriteBatch) override;
	
	~UIObject();

private:
	float m_lifeTime;
	float m_currentLifeTime;
};

