#pragma once

#include "StepTimer.h"

class Character;

class MovementController
{
public:
	MovementController(Character* parent);
	virtual ~MovementController();

	void virtual Update(DX::StepTimer const& timer) = 0;
	void virtual HandleInput(DX::StepTimer const& timer, const Vector2& mousePosition) = 0;

	/// \brief Utility functions for position the character
	void LookInLocalSpaceDirection(const Vector2& localSpaceDir);
	void LookAtLocalSpacePosition(const Vector2& localSpacePosition);

	void LookInWorldSpaceDirection(const Vector2& worldSpaceDir);
	void LookAtWorldSpacePosition(const Vector2& worldSpacePosition);

	/// \brief Uses the local rotation to calculate the current look direction relative to the parent
	/// Returns normalised vector
	const Vector2 GetLocalLookDirection() const;

	/// \brief Uses the world rotation to calculate the current look direction relative in world space
	/// Returns normalised vector
	const Vector2 GetWorldLookDirection() const;

private:
	Character* m_parent;
};

