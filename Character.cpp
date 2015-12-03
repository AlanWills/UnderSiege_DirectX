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

	if (m_active)
	{
		m_characterController->Update(timer);
	}
}