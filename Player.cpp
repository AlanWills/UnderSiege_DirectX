#include "pch.h"
#include "Player.h"
#include "InputController.h"


//-----------------------------------------------------------------------------------------------------------------------------------
Player::Player(const Vector2& localPosition, const char* loadoutDataAsset, BaseObject* parent)
	: Character(localPosition, "", LoadType::kNoLoad, parent),
	m_loadout(new Loadout(loadoutDataAsset)),
	m_gun(new Gun(m_loadout->GetData()->GetGunDataAsset()))
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
Player::~Player()
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
void Player::LoadContent(ID3D11Device* device)
{
	Character::LoadContent(device);

	m_loadout->LoadData();
	m_gun->LoadData();

	GetTextureHandler()->Load(device, GenericUtils::CharToWChar(m_loadout->GetData()->GetGameTextureAsset()));
}


//-----------------------------------------------------------------------------------------------------------------------------------
void Player::Initialize()
{
	Character::Initialize();

	SetControllerAs<InputController>();
}