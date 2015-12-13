#include "pch.h"
#include "Character.h"


//-----------------------------------------------------------------------------------------------------------------------------------
Character::Character(const Vector2& localPosition, const char* dataAsset, LoadType loadType, BaseObject* parent) :
	GameObject(localPosition, dataAsset, loadType, parent)
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
Character::~Character()
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
void Character::Update(DX::StepTimer const& timer)
{
	GameObject::Update(timer);

	if (IsActive())
	{
		m_characterController->Update(timer);
	}
}


//-----------------------------------------------------------------------------------------------------------------------------------
void Character::HandleInput(DX::StepTimer const& timer, const Vector2& mousePosition) 
{
	GameObject::HandleInput(timer, mousePosition);

	if (AcceptsInput())
	{
		m_characterController->HandleInput(timer, mousePosition);
	}
}