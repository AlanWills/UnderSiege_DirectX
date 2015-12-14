#pragma once

#include "StepTimer.h"

class ArmedCharacter;

class WeaponController
{
public:
	WeaponController(ArmedCharacter* armedCharacter);
	virtual ~WeaponController();

	void virtual Update(DX::StepTimer const& timer) = 0;
	void virtual HandleInput(DX::StepTimer const& timer, const Vector2& mousePosition) = 0;

protected:
	const ArmedCharacter* GetCharacter() const { return m_character; }

private:
	ArmedCharacter* m_character;
};

