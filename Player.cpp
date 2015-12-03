#include "pch.h"
#include "Player.h"
#include "InputCharacterController.h"


//-----------------------------------------------------------------------------------------------------------------------------------
Player::Player(const Vector2& localPosition, const char* dataAsset, LoadType loadType, BaseObject* parent)
	: Character(localPosition, dataAsset, loadType, parent)
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
Player::~Player()
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
void Player::Initialize()
{
	Character::Initialize();

	SetCharacterController<InputCharacterController>();
}