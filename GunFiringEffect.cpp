#include "pch.h"

#include "GunFiringEffect.h"


//-----------------------------------------------------------------------------------------------------------------------------------
GunFiringEffect::GunFiringEffect(const Vector2& barrelOffset, const char* muzzleTextureAsset, BaseObject* parent, LoadType loadType)
	: GameObject(muzzleTextureAsset, loadType, parent),
	m_barrelOffset(barrelOffset)
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
GunFiringEffect::~GunFiringEffect()
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
void GunFiringEffect::Initialize()
{
	GameObject::Initialize();

	// Set the position of the muzzle flash correctly
	SetLocalPosition(m_barrelOffset);
	SetOpacity(0);
}


//-----------------------------------------------------------------------------------------------------------------------------------
void GunFiringEffect::Update(DX::StepTimer const& timer)
{
	GameObject::Update(timer);

	if (IsActive())
	{
		SetOpacity(MathUtils::LerpDown(GetOpacity(), 0, (float)timer.GetElapsedSeconds() * 10.0f));
	}
}


//-----------------------------------------------------------------------------------------------------------------------------------
void GunFiringEffect::OnGunFire()
{
	SetOpacity(1);
}