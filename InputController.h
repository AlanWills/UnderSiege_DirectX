#pragma once

#include "Controller.h"

class Player;

class InputController : public Controller
{
public:
	InputController(Character* parent);
	~InputController();

	void Update(DX::StepTimer const& timer) override;
	void HandleInput(DX::StepTimer const& timer, const Vector2& mousePosition) override;

private:
	Player* m_player;
};