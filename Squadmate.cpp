#include "pch.h"

#include "Squadmate.h"
#include "SquadmateController.h"


//-----------------------------------------------------------------------------------------------------------------------------------
Squadmate::Squadmate(const Vector2& localPosition, const char* loadoutDataAsset, BaseObject* parent) :
	ArmedCharacter(localPosition, loadoutDataAsset, parent)
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
}