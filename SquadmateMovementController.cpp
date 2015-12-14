#include "pch.h"

#include "ScreenManager.h"

#include "SquadmateMovementController.h"
#include "Squadmate.h"
#include "Player.h"


//-----------------------------------------------------------------------------------------------------------------------------------
SquadmateMovementController::SquadmateMovementController(Character* squadmate) :
	MovementController(squadmate),
	m_squadmate(nullptr),
	m_followDestination(nullptr),
	m_moveDestination(squadmate->GetWorldPosition()),
	m_currentBehaviour(kFollow)
{
	m_squadmate = dynamic_cast<Squadmate*>(squadmate);
	assert(m_squadmate);
}


//-----------------------------------------------------------------------------------------------------------------------------------
SquadmateMovementController::~SquadmateMovementController()
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
void SquadmateMovementController::Update(DX::StepTimer const& timer)
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
			break;
	}
}


//-----------------------------------------------------------------------------------------------------------------------------------
void SquadmateMovementController::HandleInput(DX::StepTimer const& timer, const Vector2& mousePosition)
{
	if (ScreenManager::GetKeyboardInput().IsKeyPressed(Keyboard::F))
	{
		if (m_squadmate->GetPlayer()->GetCollider()->CheckCollisionWith(mousePosition))
		{
			m_currentBehaviour = kFollow;
		}
		else
		{
			m_moveDestination = mousePosition;
			m_currentBehaviour = kMove;
		}
	}

	// State dependent code here
	switch (m_currentBehaviour)
	{
		case kFollow:

			break;

		case kMove:
			
			break;

		default:
			break;
	}
}


//-----------------------------------------------------------------------------------------------------------------------------------
void SquadmateMovementController::Follow()
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
void SquadmateMovementController::Move()
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