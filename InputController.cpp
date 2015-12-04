#include "pch.h"

#include "ScreenManager.h"
#include "KeyboardInput.h"
#include "InputController.h"

#include "Player.h"


//-----------------------------------------------------------------------------------------------------------------------------------
InputController::InputController(Character* parent) :
	Controller(parent),
	m_player(nullptr)
{
	m_player = dynamic_cast<Player*>(parent);
	assert(m_player);
}


//-----------------------------------------------------------------------------------------------------------------------------------
InputController::~InputController()
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
void InputController::Update(DX::StepTimer const& timer)
{
	KeyboardInput& keyboard = ScreenManager::GetKeyboardInput();

	Vector2 mousePos = ScreenManager::GetGameMouse().GetInGamePosition();
	Vector2 diff(Vector2::Zero);

	// Orient the object at the mouse position
	if ((mousePos - m_player->GetWorldPosition()).Length() >= 35)
	{
		LookAtWorldSpacePosition(mousePos);
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
		m_player->GetRigidBody()->m_linearVelocity = diff * m_player->GetLoadout()->GetData()->GetSpeed();
	}
	else
	{
		m_player->GetRigidBody()->FullLinearStop();
	}
}