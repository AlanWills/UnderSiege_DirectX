#include "pch.h"
#include "Player.h"
#include "InputController.h"


//-----------------------------------------------------------------------------------------------------------------------------------
Player::Player(const Vector2& localPosition, const char* loadoutDataAsset, BaseObject* parent)
	: Character(localPosition, "", LoadType::kNoLoad, parent),
	m_loadout(new Loadout(loadoutDataAsset)),
	m_gun(nullptr)
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

	m_gun.reset(new Gun(m_loadout->GetData()->GetBarrelOffset(), m_loadout->GetData()->GetGunDataAsset(), this));
	m_gun->LoadContent(device);

	GetTextureHandler()->Load(device, GenericUtils::CharToWChar(m_loadout->GetData()->GetGameTextureAsset()));
}


//-----------------------------------------------------------------------------------------------------------------------------------
void Player::Initialize()
{
	Character::Initialize();

	m_gun->Initialize();

	SetControllerAs<InputController>();
}


//-----------------------------------------------------------------------------------------------------------------------------------
void Player::Update(DX::StepTimer const& timer)
{
	Character::Update(timer);

	m_gun->Update(timer);
}


//-----------------------------------------------------------------------------------------------------------------------------------
void Player::Draw(SpriteBatch* spriteBatch, SpriteFont* spriteFont)
{
	Character::Draw(spriteBatch, spriteFont);

	m_gun->Draw(spriteBatch, spriteFont);
}


//-----------------------------------------------------------------------------------------------------------------------------------
void Player::HandleInput(DX::StepTimer const& timer, const Vector2& mousePosition)
{
	Character::HandleInput(timer, mousePosition);

	m_gun->HandleInput(timer, mousePosition);
}