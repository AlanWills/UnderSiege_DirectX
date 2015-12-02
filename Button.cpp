#include "pch.h"
#include "Button.h"


//-----------------------------------------------------------------------------------------------------------------------------------
Button::Button(Vector2 localPosition, const std::wstring& text, const char* dataAsset, LoadType loadType, BaseObject* parent, float lifeTime) :
	Button(Vector2::Zero, localPosition, text, dataAsset, loadType, parent, lifeTime)
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
Button::Button(Vector2 size, Vector2 localPosition, const std::wstring& text, const char* dataAsset, LoadType loadType, BaseObject* parent, float lifeTime) :
	UIObject(size, localPosition, dataAsset, loadType, parent, lifeTime),
	m_label(new Label(text, this)),
	m_buttonState(kIdle),
	m_clickResetTimer(m_resetTime)
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
Button::~Button()
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
void Button::Initialize()
{
	UIObject::Initialize();

	m_label->Initialize();
}


//-----------------------------------------------------------------------------------------------------------------------------------
void Button::Update(DX::StepTimer const& timer)
{
	UIObject::Update(timer);

	if (m_active)
	{
		m_clickResetTimer += (float)timer.GetElapsedSeconds();
		if (m_clickResetTimer >= m_resetTime)
		{
			m_buttonState = ButtonState::kIdle;
		}
	}
}


//-----------------------------------------------------------------------------------------------------------------------------------
void Button::Draw(SpriteBatch* spriteBatch, SpriteFont* spriteFont)
{
	UIObject::Draw(spriteBatch, spriteFont);

	if (m_visible)
	{
		m_label->Draw(spriteBatch, spriteFont);
	}
}


//-----------------------------------------------------------------------------------------------------------------------------------
void Button::HandleInput(DX::StepTimer const& timer, const Vector2& mousePosition)
{
	UIObject::HandleInput(timer, mousePosition);

	if (m_acceptsInput)
	{
		if (m_mouseOver && m_buttonState != ButtonState::kPressed)
		{
			m_buttonState = ButtonState::kHighlighted;
		}

		if (m_selected)
		{
			if (m_buttonState != ButtonState::kPressed)
			{
				m_clickFunction();
				m_buttonState = ButtonState::kPressed;
			}
		}
	}
}