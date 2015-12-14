#include "pch.h"

#include "Player.h"
#include "Squadmate.h"

#include "SquadmateMovementController.h"
#include "SquadmateWeaponController.h"


//-----------------------------------------------------------------------------------------------------------------------------------
Squadmate::Squadmate(const Player* player, const Vector2& localPosition, const char* loadoutDataAsset, BaseObject* parent) :
	ArmedCharacter(localPosition, loadoutDataAsset, parent),
	m_player(player)
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
Squadmate::~Squadmate()
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
void Squadmate::Initialize()
{
	ArmedCharacter::Initialize();

	SquadmateMovementController* controller = SetMovementControllerAs<SquadmateMovementController>();
	controller->SetFollowDestination(&(m_player->GetLocalPosition()));

	SetWeaponControllerAs<SquadmateWeaponController>();
}