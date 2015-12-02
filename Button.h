#pragma once

#include "UIObject.h"

class Button : public UIObject
{
public:
	Button(Vector2 localPosition, const char* text, LoadType loadType = LoadType::kData, BaseObject* parent = nullptr, float lifeTime = FLT_MAX);
	Button(Vector2 size, Vector2 localPosition, const char* text, LoadType loadType = LoadType::kData, BaseObject* parent = nullptr, float lifeTime = FLT_MAX);
	~Button();

	void Update(DX::StepTimer const& timer) override;
	void HandleInput(const Ray& ray, DX::StepTimer const& timer);

	/// \brief The function that will be executed when the button is clicked
	std::function<void()> m_clickFunction;

	enum ButtonState
	{
		kIdle,
		kHighlighted,
		kPressed,
		kDisabled
	};

private:
	ButtonState m_buttonState;

	float m_clickResetTimer;
	const float m_resetTime = 0.05f;
};

