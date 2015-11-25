#include "pch.h"
#include "KeyboardInput.h"


//-----------------------------------------------------------------------------------------------------------------------------------
KeyboardInput::KeyboardInput()
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
KeyboardInput::~KeyboardInput()
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
void KeyboardInput::Update(DX::StepTimer const& timer)
{
	m_previousKeyboardState = m_currentKeyboardState;
	m_currentKeyboardState = Keyboard::Get().GetState();
}


//-----------------------------------------------------------------------------------------------------------------------------------
bool KeyboardInput::IsKeyDown(Keyboard::Keys key)
{
	return m_currentKeyboardState.IsKeyDown(key);
}


//-----------------------------------------------------------------------------------------------------------------------------------
bool KeyboardInput::IsKeyPressed(Keyboard::Keys key)
{
	return IsKeyDown(key) && m_previousKeyboardState.IsKeyUp(key);
}