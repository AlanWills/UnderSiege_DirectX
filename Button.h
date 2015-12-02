#pragma once

#include "UIObject.h"
#include "Label.h"

class Button : public UIObject
{
public:
	Button(Vector2 localPosition, const std::wstring& text, const char* dataAsset, LoadType loadType = LoadType::kData, BaseObject* parent = nullptr, float lifeTime = FLT_MAX);
	Button(Vector2 size, Vector2 localPosition, const std::wstring& text, const char* dataAsset, LoadType loadType = LoadType::kData, BaseObject* parent = nullptr, float lifeTime = FLT_MAX);
	~Button();

	void Initialize() override;

	void Update(DX::StepTimer const& timer) override;
	void Draw(SpriteBatch* spriteBatch, SpriteFont* spriteFont) override;
	void HandleInput(DX::StepTimer const& timer, const Vector2& mousePosition) override;

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
	// Button text label
	std::unique_ptr<Label> m_label;

	ButtonState m_buttonState;

	float m_clickResetTimer;
	const float m_resetTime = 0.05f;
};

