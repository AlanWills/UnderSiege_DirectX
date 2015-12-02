#include "pch.h"
#include "Label.h"


//-----------------------------------------------------------------------------------------------------------------------------------
Label::Label(const std::wstring& text, BaseObject* parent, float lifeTime) :
	UIObject("", LoadType::kNoLoad, parent, lifeTime),
	m_text(text)
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
Label::Label(const Vector2& localPosition, const std::wstring& text, BaseObject* parent, float lifeTime) :
	UIObject(localPosition, "", LoadType::kNoLoad, parent, lifeTime),
	m_text(text)
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
Label::~Label()
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
void Label::Draw(SpriteBatch* spriteBatch, SpriteFont* spriteFont)
{
	// Do not need to do any base drawing - will just be doing a custom draw using the spritefont
	spriteFont->DrawString(
		spriteBatch,
		m_text.c_str(),
		GetWorldPosition(),
		m_colour,
		GetWorldRotation(),
		spriteFont->MeasureString(m_text.c_str()) * 0.5f,
		Vector2(1, 1));
}