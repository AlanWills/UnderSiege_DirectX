#include "pch.h"

#include "Gun.h"
#include "ScreenManager.h"


//-----------------------------------------------------------------------------------------------------------------------------------
Gun::Gun(const Vector2& localPosition, const char* dataAsset, BaseObject* parent) :
	GameObject(localPosition, dataAsset, LoadType::kData, parent),
	m_gunData(new GunData(dataAsset)),
	m_currentFireTimer(0),
	m_fireTimer(0),
	m_muzzleFlash(nullptr)
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
Gun::~Gun()
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
void Gun::LoadContent(ID3D11Device* device)
{
	GameObject::LoadContent(device);

	m_gunData->LoadData();

	assert(m_gunData.get());

	// Create muzzle flash
	// The local position for GunFiringEffect is not used to mark it's position - this is calculated later
	m_muzzleFlash.reset(new GunFiringEffect(GetLocalPosition(), m_gunData->GetMuzzleFlashTextureAsset(), m_gunData->GetBulletTrailTexureAsset(), this));
	m_muzzleFlash->LoadContent(device);
}


//-----------------------------------------------------------------------------------------------------------------------------------
void Gun::Initialize()
{
	GameObject::Initialize();

	m_muzzleFlash->Initialize();
	m_fireTimer = 1 / m_gunData->GetFireRate();
}


//-----------------------------------------------------------------------------------------------------------------------------------
void Gun::Update(DX::StepTimer const& timer)
{
	GameObject::Update(timer);

	if (IsActive())
	{
		m_muzzleFlash->Update(timer);
		m_currentFireTimer += (float)timer.GetElapsedSeconds();
	}
}


//-----------------------------------------------------------------------------------------------------------------------------------
void Gun::Draw(SpriteBatch* spriteBatch, SpriteFont* spriteFont)
{
	// No drawing for the gun

	if (IsVisible())
	{
		m_muzzleFlash->Draw(spriteBatch, spriteFont);
	}
}


//-----------------------------------------------------------------------------------------------------------------------------------
void Gun::HandleInput(DX::StepTimer const& timer, const Vector2& mousePosition)
{
	GameObject::HandleInput(timer, mousePosition);

	if (AcceptsInput())
	{
		if (ScreenManager::GetGameMouse().IsPressed(GameMouse::MouseButton::kLeftButton))
		{
			if (m_currentFireTimer >= m_fireTimer)
			{
				Fire(mousePosition);
			}
		}
	}
}


//-----------------------------------------------------------------------------------------------------------------------------------
void Gun::Fire(const Vector2& targetPosition)
{
	assert(m_currentFireTimer >= m_fireTimer);

	m_muzzleFlash->OnGunFire(targetPosition);

	m_currentFireTimer = 0;

	// TO DO
	// Spawn bullet
}