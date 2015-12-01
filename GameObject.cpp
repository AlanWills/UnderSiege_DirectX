#include "pch.h"
#include "GameObject.h"
#include "ScreenManager.h"


//-----------------------------------------------------------------------------------------------------------------------------------
GameObject::GameObject(const char* dataAsset, LoadType loadType, BaseObject* parent) :
BaseObject(dataAsset, loadType, parent)
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
GameObject::GameObject(Vector2 localPosition, const char* dataAsset, LoadType loadType, BaseObject* parent) :
BaseObject(localPosition, dataAsset, loadType, parent)
{

}


//-----------------------------------------------------------------------------------------------------------------------------------
GameObject::GameObject(Vector2 size, Vector2 localPosition, const char* dataAsset, LoadType loadType, BaseObject* parent) :
BaseObject(size, localPosition, dataAsset, loadType, parent)
{

}


//-----------------------------------------------------------------------------------------------------------------------------------
GameObject::~GameObject()
{
	
}


//-----------------------------------------------------------------------------------------------------------------------------------
void GameObject::HandleInput(DX::StepTimer const& timer)
{
	// Checks if the object is accepting input - returns if not so do not need to check here
	BaseObject::HandleInput(timer);

	assert(m_collider);

	// Work out whether the mouse is over the object using the collider and mouse in game position
	m_mouseOver = m_collider->CheckCollisionWith(ScreenManager::GetGameMouse().GetInGamePosition());

	// If mouse left button isn't clicked we do not need to change the selection state
	if (!ScreenManager::GetGameMouse().IsClicked(GameMouse::MouseButton::kLeftButton))
	{
		return;
	}

	// We have clicked the mouse left button so need to check the selection status
	if (m_mouseOver && !m_selected)
	{
		// Mouse is over the object and not already selected
		m_selected = true;
	}
	else
	{
		// Otherwise we have not clicked on the object so it is not selected
		m_selected = false;
	}
}
