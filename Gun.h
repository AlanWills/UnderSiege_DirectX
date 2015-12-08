#pragma once

#include "GunData.h"

#include "BaseObjectManager.h"

#include "GameObject.h"
#include "UIObject.h"
#include "GunFiringEffect.h"

class Gun : public GameObject
{
public:
	Gun(const Vector2& localPosition, const char* dataAsset, BaseObject* parent = nullptr);
	~Gun();

	void LoadContent(ID3D11Device* device) override;
	void Initialize() override;
	void Update(DX::StepTimer const& timer) override;
	void Draw(SpriteBatch* spriteBatch, SpriteFont* spriteFont) override;
	void HandleInput(DX::StepTimer const& timer, const Vector2& mousePosition) override;

private:
	/// \brief Fire the gun.  Spawn a bullet, reset fire timers and change muzzle flash opacity
	void Fire();
	void SpawnBullet();

	std::unique_ptr<GunData> m_gunData;

	/// \brief A UI object representing the muzzle flash of the gun.  When we fire we will set it's opacity to 1 and it will (quickly) decay
	std::unique_ptr<GunFiringEffect> m_muzzleFlash;

	/// \brief All the bullets that we have fired so far
	std::unique_ptr<BaseObjectManager<GameObject>> m_bullets;

	// How long we have currently waited since we last fired
	float m_currentFireTimer;

	// How long we have to wait to fire
	float m_fireTimer;
};