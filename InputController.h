#pragma once

#include "Controller.h"

class Player;

class InputController : public Controller
{
public:
	InputController(Character* parent);
	~InputController();

	void Update(DX::StepTimer const& timer) override;

private:
	Player* m_player;
};

