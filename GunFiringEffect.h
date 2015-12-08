#pragma once

#include "GameObject.h"

class GunFiringEffect : public GameObject
{
public:
	GunFiringEffect(const Vector2& localPosition, const char* muzzleTextureAsset, BaseObject* parent, LoadType loadType = LoadType::kTexture);
	~GunFiringEffect();

	/// \brief Here we will set the local position of the muzzle effect as this is always the same and based on the size
	void Initialize() override;

	/// \brief Update the opacities
	void Update(DX::StepTimer const& timer) override;

	/// \brief Deals with the opacity and sizing when the gun is fired
	void OnGunFire();

private:
	/// \brief The local offset of the barrel from the centre of the player's texture asset
	const Vector2 m_barrelOffset;
};