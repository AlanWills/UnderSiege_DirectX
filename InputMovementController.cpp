#include "pch.h"

#include "ScreenManager.h"
#include "KeyboardInput.h"
#include "InputMovementController.h"

#include "Player.h"


//-----------------------------------------------------------------------------------------------------------------------------------
InputMovementController::InputMovementController(Character* parent) :
	MovementController(parent),
	m_player(nullptr)
{
	m_player = dynamic_cast<Player*>(parent);
	assert(m_player);
}


//-----------------------------------------------------------------------------------------------------------------------------------
InputMovementController::~InputMovementController()
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
void InputMovementController::Update(DX::StepTimer const& timer)
{
	
}


void InputMovementController::HandleInput(DX::StepTimer const& timer, const Vector2& mousePosition)
{
	KeyboardInput& keyboard = ScreenManager::GetKeyboardInput();

	Vector2 diff(Vector2::Zero);

	// Orient the object at the mouse position
	if ((mousePosition - m_player->GetWorldPosition()).Length() >= 35)
	{
		LookAtWorldSpacePosition(mousePosition);
	}
	else
	{
		// If we are very close to the mouse position, we do not want to move or rotate because it gives strange effects
		m_player->GetRigidBody()->FullStop();
		return;
	}

	// TODO
	// Used to allow a strafing behaviour for A and D
	//float angle = MathUtils::GetAngleBetweenObjectAndWorldSpaceVector(m_parent, mousePos);

	if (keyboard.IsKeyDown(Keyboard::Keys::A))
	{
		diff.x = 1;//-Vector2(cos(angle), sin(angle));
	}
	if (keyboard.IsKeyDown(Keyboard::Keys::D))
	{
		diff.x = -1;//Vector2(cos(angle), sin(angle));
	}
	if (keyboard.IsKeyDown(Keyboard::Keys::W))
	{
		diff.y = 1;
	}
	if (keyboard.IsKeyDown(Keyboard::Keys::S))
	{
		diff.y = -1;
	}

	if (diff != Vector2::Zero)
	{
		diff.Normalize();
		m_player->GetRigidBody()->SetLinearVelocity(diff * (float)m_player->GetLoadout()->GetData()->GetSpeed());
	}
	else
	{
		m_player->GetRigidBody()->FullLinearStop();
	}
}