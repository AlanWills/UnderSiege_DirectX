#include "pch.h"
#include "ScreenManager.h"

// Mouse and keyboard classes
static GameMouse m_gameMouse;
static KeyboardInput m_keyboard;

// Screen centre
static Vector2 m_screenCentre;
//-----------------------------------------------------------------------------------------------------------------------------------
Vector2 ScreenManager::GetScreenCentre()
{ 
	return m_screenCentre; 
}


//-----------------------------------------------------------------------------------------------------------------------------------
ScreenManager::ScreenManager(Microsoft::WRL::ComPtr<ID3D11Device> device, Microsoft::WRL::ComPtr<ID3D11DeviceContext> deviceContext, float screenWidth, float screenHeight) :
m_device(device),
m_deviceContext(deviceContext),
m_spriteBatch(new SpriteBatch(deviceContext.Get())),
m_states(new CommonStates(device.Get()))
{
	m_screenCentre = Vector2(screenWidth, screenHeight) * 0.5f;
}


//-----------------------------------------------------------------------------------------------------------------------------------
ScreenManager::~ScreenManager()
{
	// Need to delete all the screens here
	for (BaseScreen* screen : m_activeScreens)
	{
		delete screen;
	}

	m_activeScreens.clear();
}


//-----------------------------------------------------------------------------------------------------------------------------------
void ScreenManager::LoadContent()
{
	m_gameMouse.LoadContent(m_device.Get());
}


//-----------------------------------------------------------------------------------------------------------------------------------
void ScreenManager::Initialize()
{
	m_gameMouse.Initialize();
}


//-----------------------------------------------------------------------------------------------------------------------------------
void ScreenManager::Update(DX::StepTimer const& timer)
{
	m_gameMouse.Update(timer);

	for (BaseScreen* screen : m_activeScreens)
	{
		// Screen updating and input handling - can have this all in one loop as we will probably only ever have one active screen at a time
		screen->Update(timer);
		screen->HandleInput(timer);
	}

	for (BaseScreen* screen : m_screensToDelete)
	{
		// Clean up dead screens
		m_activeScreens.remove(screen);
		delete screen;
	}

	m_screensToDelete.clear();
}


//-----------------------------------------------------------------------------------------------------------------------------------
void ScreenManager::Draw()
{
	m_spriteBatch->Begin(SpriteSortMode_Deferred, m_states->NonPremultiplied());

	m_activeScreens.back()->DrawBackground(m_spriteBatch.get());

	m_spriteBatch->End();

	m_spriteBatch->Begin(SpriteSortMode_Deferred, m_states->NonPremultiplied());

	for (BaseScreen* screen : m_activeScreens)
	{
		screen->DrawInGameObjects(m_spriteBatch.get());
	}

	m_spriteBatch->End();

	m_spriteBatch->Begin(SpriteSortMode_Deferred, m_states->NonPremultiplied());

	for (BaseScreen* screen : m_activeScreens)
	{
		screen->DrawScreenObjects(m_spriteBatch.get());
	}

	m_gameMouse.Draw(m_spriteBatch.get());

	m_spriteBatch->End();
}


//-----------------------------------------------------------------------------------------------------------------------------------
void ScreenManager::HandleInput(DX::StepTimer const& timer)
{
	m_gameMouse.HandleInput(timer);

	for (BaseScreen* screen : m_activeScreens)
	{
		screen->HandleInput(timer);
	}
}


//-----------------------------------------------------------------------------------------------------------------------------------
void ScreenManager::AddScreen(BaseScreen* screenToAdd)
{
	screenToAdd->LoadContent();
	screenToAdd->Initialize();

	m_activeScreens.push_back(screenToAdd);
}


//-----------------------------------------------------------------------------------------------------------------------------------
void ScreenManager::RemoveScreen(BaseScreen* screenToRemove)
{
	m_screensToDelete.push_back(screenToRemove);
}
