#include "pch.h"

#include "Player.h"
#include "Squadmate.h"
#include "SquadmateController.h"


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

	SetControllerAs<SquadmateController>();
	GetControllerAs<SquadmateController>()->SetFollowDestination(&(m_player->GetLocalPosition()));
}