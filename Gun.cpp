#include "pch.h"

#include "Gun.h"
#include "ScreenManager.h"


//-----------------------------------------------------------------------------------------------------------------------------------
Gun::Gun(const Vector2& localPosition, const char* dataAsset, BaseObject* parent) :
	GameObject(localPosition, dataAsset, LoadType::kData, parent),
	m_gunData(new GunData(dataAsset)),
	m_currentFireTimer(0),
	m_fireTimer(0),
	m_muzzleFlash(nullptr),
	m_bullets(nullptr)
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
	m_muzzleFlash.reset(new GunFiringEffect(GetLocalPosition(), m_gunData->GetMuzzleFlashTextureAsset(), this));
	m_muzzleFlash->LoadContent(device);

	m_bullets.reset(new BaseObjectManager<GameObject>(device));
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

		m_bullets->Update(timer);
	}
}


//-----------------------------------------------------------------------------------------------------------------------------------
void Gun::Draw(SpriteBatch* spriteBatch, SpriteFont* spriteFont)
{
	// No drawing for the gun

	if (IsVisible())
	{
		m_bullets->Draw(spriteBatch, spriteFont);
		m_muzzleFlash->Draw(spriteBatch, spriteFont);
	}
}


//-----------------------------------------------------------------------------------------------------------------------------------
void Gun::Fire()
{
	if (!CanFire())
	{
		// We cannot fire so do not continue
		return;
	}

	assert(m_currentFireTimer >= m_fireTimer);

	m_muzzleFlash->OnGunFire();

	m_currentFireTimer = 0;

	// Spawn bullet - would be better to clone rather than load from scratch here
	SpawnBullet();
}


//-----------------------------------------------------------------------------------------------------------------------------------
const bool Gun::CanFire() const
{
	return m_currentFireTimer >= m_fireTimer;
}


//-----------------------------------------------------------------------------------------------------------------------------------
void Gun::SpawnBullet()
{
	// Generate a number between -1 and 1 - used to create a spread effect when firing bullets
	float spread = (static_cast<float>(2 * rand()) / static_cast<float>(RAND_MAX)) - 1;

	GameObject* bullet = new GameObject(Vector2(1, 30), m_muzzleFlash->GetWorldPosition(), m_gunData->GetBulletTexureAsset(), LoadType::kTexture);
	bullet->SetLocalRotation(GetWorldRotation() + spread * m_gunData->GetBulletSpread());
	m_bullets->AddObject(bullet, true, true);
	bullet->GetRigidBody()->SetLinearVelocity(Vector2(0, 2000));
}