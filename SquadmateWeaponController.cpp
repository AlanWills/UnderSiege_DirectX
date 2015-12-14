#include "pch.h"

#include "SquadmateWeaponController.h"


//-----------------------------------------------------------------------------------------------------------------------------------
SquadmateWeaponController::SquadmateWeaponController(ArmedCharacter* parent) :
	WeaponController(parent)
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
SquadmateWeaponController::~SquadmateWeaponController()
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
void SquadmateWeaponController::Update(DX::StepTimer const& timer)
{
	switch (m_currentBehaviour)
	{
	case kAttackPosition:
		
		break;

	case kAttackTarget:
		
		break;

	case kWait:
	default:
		break;
	}
}


//-----------------------------------------------------------------------------------------------------------------------------------
void SquadmateWeaponController::HandleInput(DX::StepTimer const& timer, const Vector2& mousePosition)
{
	switch (m_currentBehaviour)
	{
	default:
		break;
	}
}