#include "pch.h"
#include "Button.h"


//-----------------------------------------------------------------------------------------------------------------------------------
Button::Button(Vector2 localPosition, const char* dataAsset, BaseObject* parent, float lifeTime) :
	ScreenUIObject(localPosition, dataAsset, parent, lifeTime),
	m_buttonState(kIdle),
	m_clickResetTimer(m_resetTime)
{

}


//-----------------------------------------------------------------------------------------------------------------------------------
Button::Button(Vector2 size, Vector2 localPosition, const char* dataAsset, BaseObject* parent, float lifeTime) :
	ScreenUIObject(size, localPosition, dataAsset, parent, lifeTime),
	m_buttonState(kIdle)
{

}


//-----------------------------------------------------------------------------------------------------------------------------------
Button::~Button()
{

}


//-----------------------------------------------------------------------------------------------------------------------------------
void Button::Update(DX::StepTimer const& timer)
{
	if (m_active)
	{
		m_clickResetTimer += timer.GetElapsedSeconds();
		if (m_clickResetTimer >= m_resetTime)
		{
			m_buttonState = ButtonState::kIdle;
		}
	}
}


//-----------------------------------------------------------------------------------------------------------------------------------
void Button::HandleInput(DX::StepTimer const& timer)
{
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