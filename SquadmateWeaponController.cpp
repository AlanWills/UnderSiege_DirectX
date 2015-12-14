#include "pch.h"

#include "ScreenManager.h"

#include "SquadmateWeaponController.h"
#include "SquadmateMovementController.h"
#include "Squadmate.h"


//-----------------------------------------------------------------------------------------------------------------------------------
SquadmateWeaponController::SquadmateWeaponController(ArmedCharacter* parent) :
	WeaponController(parent)
{
	m_squadmate = dynamic_cast<Squadmate*>(parent);
	assert(m_squadmate);
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
			m_squadmate->GetMovementControllerAs<SquadmateMovementController>()->LookAtWorldSpacePosition(m_attackPosition);
			m_squadmate->GetGun()->Fire();
			break;

		case kAttackTarget:
			m_squadmate->GetMovementControllerAs<SquadmateMovementController>()->LookAtWorldSpacePosition(m_target->GetWorldPosition());
			m_squadmate->GetGun()->Fire();
			break;

		case kWait:
		default:
			break;
	}
}


//-----------------------------------------------------------------------------------------------------------------------------------
void SquadmateWeaponController::HandleInput(DX::StepTimer const& timer, const Vector2& mousePosition)
{
	if (ScreenManager::GetKeyboardInput().IsKeyPressed(Keyboard::E))
	{
		m_attackPosition = mousePosition;
		m_currentBehaviour = kAttackPosition;
	}

	// State dependent code
	switch (m_currentBehaviour)
	{
		default:
			break;
	}
}