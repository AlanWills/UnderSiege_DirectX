#include "pch.h"

#include "Player.h"
#include "InputController.h"


//-----------------------------------------------------------------------------------------------------------------------------------
Player::Player(const Vector2& localPosition, const char* loadoutDataAsset, BaseObject* parent)
	: ArmedCharacter(localPosition, loadoutDataAsset, parent)
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
Player::~Player()
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
void Player::Initialize()
{
	ArmedCharacter::Initialize();

	SetControllerAs<InputController>();
}