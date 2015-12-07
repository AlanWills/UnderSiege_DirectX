#include "pch.h"

#include "Gun.h"
#include "ScreenManager.h"


//-----------------------------------------------------------------------------------------------------------------------------------
Gun::Gun(const Vector2& localPosition, const char* dataAsset, BaseObject* parent) :
	GameObject(localPosition, dataAsset, LoadType::kNoLoad, parent),
	m_gunData(new GunData(dataAsset)),
	m_currentFireTimer(0),
	m_fireTimer(0)
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

	m_muzzleFlash->LoadContent(device);
}


//-----------------------------------------------------------------------------------------------------------------------------------
void Gun::Initialize()
{
	GameObject::Initialize();

	m_muzzleFlash->Initialize();
	m_fireTimer = 1 / m_gunData->GetFireRate();
	m_currentFireTimer = m_fireTimer;
}


//-----------------------------------------------------------------------------------------------------------------------------------
void Gun::Update(DX::StepTimer const& timer)
{
	GameObject::Update(timer);

	if (IsActive())
	{
		m_muzzleFlash->SetOpacity(MathUtils::LerpDown(m_muzzleFlash->GetOpacity(), 0, (float)timer.GetElapsedSeconds()));
		m_currentFireTimer += (float)timer.GetElapsedSeconds();
	}
}


//-----------------------------------------------------------------------------------------------------------------------------------
void Gun::Draw(SpriteBatch* spriteBatch, SpriteFont* spriteFont)
{
	GameObject::Draw(spriteBatch, spriteFont);

	if (IsVisible())
	{
		m_muzzleFlash->Draw(spriteBatch, spriteFont);
	}
}


//-----------------------------------------------------------------------------------------------------------------------------------
void Gun::HandleInput(DX::StepTimer const& timer, const Vector2& mousePosition)
{
	GameObject::HandleInput(timer, mousePosition);

	if (ScreenManager::GetGameMouse().IsClicked(GameMouse::MouseButton::kLeftButton))
	{
		if (m_currentFireTimer >= m_fireTimer)
		{
			Fire();
		}
	}
}


//-----------------------------------------------------------------------------------------------------------------------------------
void Gun::Fire()
{
	assert(m_currentFireTimer >= m_fireTimer);
	m_muzzleFlash->SetOpacity(1);
	m_currentFireTimer = 0;

	// TO DO
	// Spawn bullet
}