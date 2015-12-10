#include "pch.h"

#include "SquadmateController.h"
#include "Squadmate.h"


//-----------------------------------------------------------------------------------------------------------------------------------
SquadmateController::SquadmateController(Character* squadmate) :
	Controller(squadmate),
	m_squadmate(nullptr)
{
	m_squadmate = dynamic_cast<Squadmate*>(squadmate);
	assert(m_squadmate);
}


//-----------------------------------------------------------------------------------------------------------------------------------
SquadmateController::~SquadmateController()
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
void SquadmateController::Update(DX::StepTimer const& timer)
{

}