#pragma once

#include "WeaponController.h"

class ArmedCharacter;

class InputWeaponController : public WeaponController
{
public:
	InputWeaponController(ArmedCharacter* armedCharacter);
	~InputWeaponController();

	void Update(DX::StepTimer const& timer) override;
	void HandleInput(DX::StepTimer const& timer, const Vector2& mousePosition) override;
};

