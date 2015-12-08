#pragma once

#include "GunData.h"

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
	void Fire(const Vector2& targetPosition);

	std::unique_ptr<GunData> m_gunData;

	/// \brief A UI object representing the muzzle flash of the gun.  When we fire we will set it's opacity to 1 and it will (quickly) decay
	std::unique_ptr<GunFiringEffect> m_muzzleFlash;

	// How long we have currently waited since we last fired
	float m_currentFireTimer;

	// How long we have to wait to fire
	float m_fireTimer;
};