#include "pch.h"

#include "ArmedCharacter.h"


//-----------------------------------------------------------------------------------------------------------------------------------
ArmedCharacter::ArmedCharacter(const Vector2& localPosition, const char* loadoutDataAsset, BaseObject* parent) :
	Character(localPosition, "", LoadType::kNoLoad, parent),
	m_loadout(new Loadout(loadoutDataAsset)),
	m_gun(nullptr),
	m_weaponController(nullptr)
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
ArmedCharacter::~ArmedCharacter()
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
void ArmedCharacter::LoadContent(ID3D11Device* device)
{
	Character::LoadContent(device);

	m_loadout->LoadData();

	m_gun.reset(new Gun(m_loadout->GetData()->GetBarrelOffset(), m_loadout->GetData()->GetGunDataAsset(), this));
	m_gun->LoadContent(device);

	GetTextureHandler()->Load(device, GenericUtils::CharToWChar(m_loadout->GetData()->GetGameTextureAsset()));
}


//-----------------------------------------------------------------------------------------------------------------------------------
void ArmedCharacter::Initialize()
{
	Character::Initialize();

	m_gun->Initialize();
}


//-----------------------------------------------------------------------------------------------------------------------------------
void ArmedCharacter::Update(DX::StepTimer const& timer)
{
	Character::Update(timer);

	m_weaponController->Update(timer);
	m_gun->Update(timer);
}


//-----------------------------------------------------------------------------------------------------------------------------------
void ArmedCharacter::Draw(SpriteBatch* spriteBatch, SpriteFont* spriteFont)
{
	Character::Draw(spriteBatch, spriteFont);

	m_gun->Draw(spriteBatch, spriteFont);
}


//-----------------------------------------------------------------------------------------------------------------------------------
void ArmedCharacter::HandleInput(DX::StepTimer const& timer, const Vector2& mousePosition)
{
	Character::HandleInput(timer, mousePosition);

	m_weaponController->HandleInput(timer, mousePosition);
}