#include "pch.h"
#include "GameMouse.h"
#include "ScreenManager.h"


//-----------------------------------------------------------------------------------------------------------------------------------
GameMouse::GameMouse()
	: ScreenUIObject("cursor_blue.png", LoadType::kTexture),
	m_mouse(new Mouse()),
	m_mouseButtonState(new Mouse::ButtonStateTracker()),
	m_clickDelayTimer(0.02f)
{
	// This hides the window cursor so that we can draw our own one instead
	// We still maintain the functionality though (wrapped up in Mouse.h DirectXTK)
	ShowCursor(false);

	for (int i = 0; i < MouseButton::kNumButtons; i++)
	{
		m_mouseClickStates[i] = false;
	}
}


//-----------------------------------------------------------------------------------------------------------------------------------
GameMouse::~GameMouse()
{
	
}


//-----------------------------------------------------------------------------------------------------------------------------------
void GameMouse::Update(DX::StepTimer const& timer)
{
	ScreenUIObject::Update(timer);

	// Update mouse states
	m_currentMouseState = m_mouse->GetState();
	m_mouseButtonState->Update(m_currentMouseState);

	// Update mouse position
	m_localPosition = Vector2((float)m_currentMouseState.x, (float)m_currentMouseState.y);
}


//-----------------------------------------------------------------------------------------------------------------------------------
void GameMouse::Draw(SpriteBatch* spriteBatch, SpriteFont* spriteFont)
{
	if (m_visible)
	{
		spriteBatch->Draw(
			m_textureHandler->GetTexture(), 
			GetWorldPosition(), 
			nullptr, 
			m_colour * m_opacity,
			GetWorldRotation(), 
			Vector2::Zero, 
			XMVectorDivide(m_size, m_textureHandler->m_dimensions));
	}
}


//-----------------------------------------------------------------------------------------------------------------------------------
void GameMouse::HandleInput(DX::StepTimer const& timer)
{
	// If the value in the Mouse.h class is true that means it is down
	if (m_mouseButtonState->leftButton == Mouse::ButtonStateTracker::PRESSED && m_clickDelayTimer >= 0.02f)
	{
		m_mouseClickStates[MouseButton::kLeftButton] = true;
		m_clickDelayTimer = 0;
	}
	else
	{
		m_mouseClickStates[MouseButton::kLeftButton] = false;
		m_clickDelayTimer += (float)timer.GetElapsedSeconds();
	}

	if (m_mouseButtonState->middleButton == Mouse::ButtonStateTracker::PRESSED && m_clickDelayTimer >= 0.02f)
	{
		m_mouseClickStates[MouseButton::kMiddleButton] = true;
		m_clickDelayTimer = 0;
	}
	else
	{
		m_mouseClickStates[MouseButton::kMiddleButton] = false;
		m_clickDelayTimer += (float)timer.GetElapsedSeconds();
	}

	if (m_mouseButtonState->rightButton == Mouse::ButtonStateTracker::PRESSED && m_clickDelayTimer >= 0.02f)
	{
		m_mouseClickStates[MouseButton::kRightButton] = true;
		m_clickDelayTimer = 0;
	}
	else
	{
		m_mouseClickStates[MouseButton::kRightButton] = false;
		m_clickDelayTimer += (float)timer.GetElapsedSeconds();
	}
}


//-----------------------------------------------------------------------------------------------------------------------------------
Vector2 GameMouse::GetInGamePosition()
{
	return ScreenManager::GetCamera().ScreenToGameCoords(m_localPosition);
}