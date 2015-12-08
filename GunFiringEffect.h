#pragma once

#include "UIObject.h"

class GunFiringEffect : public UIObject
{
public:
	GunFiringEffect(const Vector2& localPosition, const char* muzzleTextureAsset, const char* bulletTrailTextureAsset, BaseObject* parent, LoadType loadType = LoadType::kTexture);
	~GunFiringEffect();

	void LoadContent(ID3D11Device* device) override;

	/// \brief Here we will set the local position of the muzzle effect as this is always the same and based on the size
	void Initialize() override;

	/// \brief Update the opacities
	void Update(DX::StepTimer const& timer) override;
	void Draw(SpriteBatch* spriteBatch, SpriteFont* spriteFont) override;

	/// \brief Deals with the opacity and sizing when the gun is fired
	void OnGunFire(const Vector2& targetPosition);

private:
	/// \brief A trail from the gun barrel to the mouse location
	std::unique_ptr<UIObject> m_bulletTrail;

	/// \brief The local offset of the barrel from the centre of the player's texture asset
	const Vector2 m_barrelOffset;
};