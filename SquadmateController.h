#pragma once

#include "Controller.h"

class Squadmate;

class SquadmateController : public Controller
{
public:
	SquadmateController(Character* parent);
	~SquadmateController();

	void Update(DX::StepTimer const& timer) override;

private:
	Squadmate* m_squadmate;
};

