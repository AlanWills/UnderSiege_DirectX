#pragma once

#include "Character.h"
#include "Loadout.h"
#include "Gun.h"

#include "WeaponController.h"

class ArmedCharacter : public Character
{
public:
	ArmedCharacter(const Vector2& localPosition, const char* loadoutDataAsset, BaseObject* parent = nullptr);
	~ArmedCharacter();

	void LoadContent(ID3D11Device* device) override;
	void Initialize() override;
	void Update(DX::StepTimer const& timer) override;
	void Draw(SpriteBatch* spriteBatch, SpriteFont* spriteFont) override;
	void HandleInput(DX::StepTimer const& timer, const Vector2& mousePosition) override;

	const Loadout* GetLoadout() const { return m_loadout.get(); }
	Gun* GetGun() const { return m_gun.get(); }

protected:
	template <typename T>
	T* SetWeaponControllerAs();

	template <typename T>
	T* GetWeaponControllerAs() const;

	const WeaponController* GetWeaponController() const { return m_weaponController.get(); }

private:
	/// \brief Data for this armed character
	std::unique_ptr<Loadout> m_loadout;
	std::unique_ptr<Gun> m_gun;

	std::unique_ptr<WeaponController> m_weaponController;
};


template <typename T>
T* ArmedCharacter::SetWeaponControllerAs()
{
	m_weaponController.reset(new T(this));
	return dynamic_cast<T*>(m_weaponController.get());
}


template <typename T>
T* ArmedCharacter::GetWeaponControllerAs() const
{
	return dynamic_cast<T*>(m_weaponController.get());
}