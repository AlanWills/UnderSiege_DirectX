#include "pch.h"
#include "Player.h"
#include "InputController.h"


//-----------------------------------------------------------------------------------------------------------------------------------
Player::Player(const Vector2& localPosition, const char* loadoutDataAsset, BaseObject* parent)
	: Character(localPosition, loadoutDataAsset, LoadType::kNoLoad, parent),
	m_loadout(nullptr)
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

	m_loadout.reset(new Loadout(GetDataAsset()));
	m_loadout->LoadData();

	GetTextureHandler()->Load(device, GenericUtils::CharToWChar(m_loadout->GetData()->GetCharacterTextureAsset()));
}


//-----------------------------------------------------------------------------------------------------------------------------------
void Player::Initialize()
{
	Character::Initialize();

	SetCharacterController<InputController>();
}