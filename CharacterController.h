#pragma once

#include "StepTimer.h"
#include "GameObject.h"

class CharacterController
{
public:
	CharacterController(GameObject* parent);
	virtual ~CharacterController();

	void virtual Update(DX::StepTimer const& timer) = 0;

protected:
	GameObject* m_parent;
};

