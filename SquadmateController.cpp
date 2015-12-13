#include "pch.h"

#include "ScreenManager.h"

#include "SquadmateController.h"
#include "Squadmate.h"


//-----------------------------------------------------------------------------------------------------------------------------------
SquadmateController::SquadmateController(Character* squadmate) :
	Controller(squadmate),
	m_squadmate(nullptr),
	m_followDestination(nullptr),
	m_moveDestination(squadmate->GetWorldPosition()),
	m_currentBehaviour(kMove)
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
	switch (m_currentBehaviour)
	{
		case kFollow:
			Follow();
			break;

		case kMove:
			Move();
			break;
		
		default:
			return;
	}
}


//-----------------------------------------------------------------------------------------------------------------------------------
void SquadmateController::HandleInput(DX::StepTimer const& timer, const Vector2& mousePosition)
{
	switch (m_currentBehaviour)
	{
		case kMove:
			if (ScreenManager::GetKeyboardInput().IsKeyPressed(Keyboard::F))
			{
				m_moveDestination = mousePosition;
			}
			break;

		default:
			return;
	}
}


//-----------------------------------------------------------------------------------------------------------------------------------
void SquadmateController::Follow()
{
	assert(m_followDestination);

	Vector2 followDestination = *m_followDestination;
	float distanceToDestSquared = Vector2::DistanceSquared(m_squadmate->GetWorldPosition(), followDestination);

	if (distanceToDestSquared <= 200 * 200)
	{
		m_squadmate->GetRigidBody()->FullStop();
		return;
	}

	LookAtWorldSpacePosition(*m_followDestination);

	m_squadmate->GetRigidBody()->SetLinearVelocity(Vector2(0, (float)m_squadmate->GetLoadout()->GetData()->GetSpeed()));
}


//-----------------------------------------------------------------------------------------------------------------------------------
void SquadmateController::Move()
{
	float distanceToDestSquared = Vector2::DistanceSquared(m_squadmate->GetWorldPosition(), m_moveDestination);
	if (distanceToDestSquared <= 30 * 30)
	{
		m_squadmate->GetRigidBody()->FullStop();
		return;
	}

	LookAtWorldSpacePosition(m_moveDestination);

	m_squadmate->GetRigidBody()->SetLinearVelocity(Vector2(0, (float)m_squadmate->GetLoadout()->GetData()->GetSpeed()));
}