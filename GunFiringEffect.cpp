#include "pch.h"

#include "GunFiringEffect.h"


//-----------------------------------------------------------------------------------------------------------------------------------
GunFiringEffect::GunFiringEffect(const Vector2& barrelOffset, const char* muzzleTextureAsset, const char* bulletTrailTextureAsset, BaseObject* parent, LoadType loadType)
	: UIObject(muzzleTextureAsset, loadType, parent),
	m_bulletTrail(new UIObject(bulletTrailTextureAsset, LoadType::kTexture)),
	m_barrelOffset(barrelOffset)
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
GunFiringEffect::~GunFiringEffect()
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
void GunFiringEffect::LoadContent(ID3D11Device* device)
{
	UIObject::LoadContent(device);

	m_bulletTrail->LoadContent(device);
}


//-----------------------------------------------------------------------------------------------------------------------------------
void GunFiringEffect::Initialize()
{
	UIObject::Initialize();

	// Set the position of the muzzle flash correctly
	SetLocalPosition(m_barrelOffset);
	SetOpacity(0);

	m_bulletTrail->Initialize();
	m_bulletTrail->SetOpacity(0);
}


//-----------------------------------------------------------------------------------------------------------------------------------
void GunFiringEffect::Update(DX::StepTimer const& timer)
{
	UIObject::Update(timer);

	if (IsActive())
	{
		SetOpacity(MathUtils::LerpDown(GetOpacity(), 0, (float)timer.GetElapsedSeconds() * 10.0f));
		
		m_bulletTrail->SetOpacity(MathUtils::LerpDown(m_bulletTrail->GetOpacity(), 0, (float)timer.GetElapsedSeconds() * 10.0f));
	}
}


//-----------------------------------------------------------------------------------------------------------------------------------
void GunFiringEffect::Draw(SpriteBatch* spriteBatch, SpriteFont* spriteFont)
{
	if (IsVisible())
	{
		m_bulletTrail->Draw(spriteBatch, spriteFont);
	}

	UIObject::Draw(spriteBatch, spriteFont);
}


//-----------------------------------------------------------------------------------------------------------------------------------
void GunFiringEffect::OnGunFire(const Vector2& targetPosition)
{
	SetOpacity(1);

	// Set the opacities to 1 and change the position and rotation of the bullet trail
	m_bulletTrail->SetOpacity(1);
	m_bulletTrail->SetLocalRotation(GetWorldRotation());

	Vector2 diff(targetPosition - GetWorldPosition());
	m_bulletTrail->SetLocalPosition(GetWorldPosition() + (diff) * 0.5f);
	m_bulletTrail->SetSize(Vector2(m_bulletTrail->GetSize().x, diff.Length()));
}