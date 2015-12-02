#include "pch.h"
#include "Button.h"


//-----------------------------------------------------------------------------------------------------------------------------------
Button::Button(Vector2 localPosition, const char* dataAsset, LoadType loadType, BaseObject* parent, float lifeTime) :
	UIObject(localPosition, dataAsset, loadType, parent, lifeTime),
	m_buttonState(kIdle),
	m_clickResetTimer(m_resetTime)
{

}


//-----------------------------------------------------------------------------------------------------------------------------------
Button::Button(Vector2 size, Vector2 localPosition, const char* dataAsset, LoadType loadType, BaseObject* parent, float lifeTime) :
	UIObject(size, localPosition, dataAsset, loadType, parent, lifeTime),
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
		m_clickResetTimer += (float)timer.GetElapsedSeconds();
		if (m_clickResetTimer >= m_resetTime)
		{
			m_buttonState = ButtonState::kIdle;
		}
	}
}


//-----------------------------------------------------------------------------------------------------------------------------------
void Button::HandleInput(const Ray& ray, DX::StepTimer const& timer)
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