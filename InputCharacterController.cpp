#include "pch.h"

#include "ScreenManager.h"
#include "KeyboardInput.h"
#include "InputCharacterController.h"


//-----------------------------------------------------------------------------------------------------------------------------------
InputCharacterController::InputCharacterController(GameObject* parent) :
	CharacterController(parent)
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
InputCharacterController::~InputCharacterController()
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
void InputCharacterController::Update(DX::StepTimer const& timer)
{
	KeyboardInput& keyboard = ScreenManager::GetKeyboardInput();
	Vector2 diff(Vector2::Zero);

	if (keyboard.IsKeyDown(Keyboard::Keys::A))
	{
		diff.x = 1;
	}
	if (keyboard.IsKeyDown(Keyboard::Keys::D))
	{
		diff.x = -1;
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
		m_parent->GetRigidBody()->m_linearVelocity = diff * 100;
	}
	else
	{
		m_parent->GetRigidBody()->FullLinearStop();
	}
}