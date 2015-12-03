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

	if (keyboard.IsKeyDown(Keyboard::Keys::Left))
	{
		diff.x = -1;
	}
	if (keyboard.IsKeyDown(Keyboard::Keys::Right))
	{
		diff.x = 1;
	}
	if (keyboard.IsKeyDown(Keyboard::Keys::Up))
	{
		diff.y = -1;
	}
	if (keyboard.IsKeyDown(Keyboard::Keys::Down))
	{
		diff.y = 1;
	}

	if (diff != Vector2::Zero)
	{
		diff.Normalize();
		m_parent->GetRigidBody()->m_linearVelocity = diff * (float)timer.GetElapsedSeconds();
	}
}