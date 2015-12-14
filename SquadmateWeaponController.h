#pragma once

#include "WeaponController.h"

class Squadmate;
class Character;

class SquadmateWeaponController : public WeaponController
{
public:
	enum WeaponBehaviour
	{
		kWait,
		kAttackPosition,
		kAttackTarget,
	};

	SquadmateWeaponController(ArmedCharacter* parent);
	~SquadmateWeaponController();

	void Update(DX::StepTimer const& timer) override;
	void HandleInput(DX::StepTimer const& timer, const Vector2& mousePosition) override;

	void SetState(const WeaponBehaviour attackBehaviour) { m_currentBehaviour = attackBehaviour; }
	void SetTarget(const Character* target) { m_target = target; }

private:
	Squadmate* m_squadmate;

	/// \brief Private variables used for the behaviours
	Vector2 m_attackPosition;						// Position we will be attacking - used for attack position command
	const Character* m_target;						// Pointer to a Vector2 we will use to attack - probably the Target's world position

	/// \brief Our current behaviour state
	WeaponBehaviour m_currentBehaviour;
};

