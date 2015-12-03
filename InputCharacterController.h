#pragma once

#include "CharacterController.h"

class InputCharacterController : public CharacterController
{
public:
	InputCharacterController(GameObject* parent);
	~InputCharacterController();

	void Update(DX::StepTimer const& timer) override;
};

