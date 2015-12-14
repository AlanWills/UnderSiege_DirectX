#pragma once

#include "MovementController.h"

class Player;

class InputMovementController : public MovementController
{
public:
	InputMovementController(Character* parent);
	~InputMovementController();

	void Update(DX::StepTimer const& timer) override;
	void HandleInput(DX::StepTimer const& timer, const Vector2& mousePosition) override;

private:
	Player* m_player;
};