#include "pch.h"
#include "UIObject.h"


//-----------------------------------------------------------------------------------------------------------------------------------
UIObject::UIObject(const char* dataAsset, BaseObject* parent, float lifeTime) :
	BaseObject(dataAsset, parent),
	m_lifeTime(lifeTime),
	m_currentLifeTime(0)
{

}


//-----------------------------------------------------------------------------------------------------------------------------------
UIObject::UIObject(Vector2 localPosition, const char* dataAsset, BaseObject* parent, float lifeTime) :
	BaseObject(localPosition, dataAsset, parent),
	m_lifeTime(lifeTime),
	m_currentLifeTime(0)
{

}


//-----------------------------------------------------------------------------------------------------------------------------------
UIObject::UIObject(Vector2 size, Vector2 localPosition, const char* dataAsset, BaseObject* parent, float lifeTime) :
	BaseObject(size, localPosition, dataAsset, parent),
	m_lifeTime(lifeTime),
	m_currentLifeTime(0)
{

}


//-----------------------------------------------------------------------------------------------------------------------------------
UIObject::~UIObject()
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
void UIObject::Update(DX::StepTimer const& timer)
{
	BaseObject::Update(timer);

	m_currentLifeTime += (float)timer.GetElapsedSeconds();
	if (m_currentLifeTime > m_lifeTime)
	{
		// This UIObject has been alive for longer than its lifetime so it dies
		// and will be cleared up by whatever manager is in charge of it
		Die();
	}
}


//-----------------------------------------------------------------------------------------------------------------------------------
void UIObject::Draw(SpriteBatch* spriteBatch)
{
	BaseObject::Draw(spriteBatch);

	// draw text with spritefont here if visible
}