#include "pch.h"
#include "ScreenManager.h"


// Screen centre
static Vector2 m_screenCentre;
//-----------------------------------------------------------------------------------------------------------------------------------
Vector2 ScreenManager::GetScreenCentre()
{ 
	return m_screenCentre; 
}


//-----------------------------------------------------------------------------------------------------------------------------------
ScreenManager::ScreenManager(ID3D11Device* device, ID3D11DeviceContext* deviceContext, float screenWidth, float screenHeight) :
m_device(device),
m_deviceContext(deviceContext),
m_spriteBatch(nullptr),
m_states(nullptr),
{
	m_screenCentre = Vector2(screenWidth, screenHeight) * 0.5f;
}


//-----------------------------------------------------------------------------------------------------------------------------------
ScreenManager::~ScreenManager()
{
	delete m_spriteBatch;
	delete m_states;

	// Need to delete all the screens here
	for (BaseScreen* screen : m_screensToAdd)
	{
		delete screen;
	}

	for (BaseScreen* screen : m_activeScreens)
	{
		delete screen;
	}

	for (BaseScreen* screen : m_screensToRemove)
	{
		delete screen;
	}

	m_screensToAdd.clear();
	m_activeScreens.clear();
	m_screensToRemove.clear();
}


//-----------------------------------------------------------------------------------------------------------------------------------
void ScreenManager::LoadContent()
{
	m_spriteBatch = new SpriteBatch(m_deviceContext);
	m_states = new CommonStates(m_device);
}


//-----------------------------------------------------------------------------------------------------------------------------------
void ScreenManager::Initialize()
{
	for (BaseScreen* screen : m_screensToAdd)
	{
		m_activeScreens.push_back(screen);
	}

	m_screensToAdd.clear();
}


//-----------------------------------------------------------------------------------------------------------------------------------
void ScreenManager::Update(DX::StepTimer const& timer)
{
	for (BaseScreen* screen : m_screensToAdd)
	{
		m_activeScreens.push_back(screen);
	}

	m_screensToAdd.clear();

	for (BaseScreen* screen : m_activeScreens)
	{
		// Screen updating and input handling - can have this all in one loop as we will probably only ever have one active screen at a time
		screen->Update(timer);
		screen->HandleInput(timer);
	}

	for (BaseScreen* screen : m_screensToRemove)
	{
		m_activeScreens.remove(screen);
		delete screen;
	}

	m_screensToRemove.clear();
}


//-----------------------------------------------------------------------------------------------------------------------------------
void ScreenManager::Draw()
{
	m_spriteBatch->Begin(SpriteSortMode_Deferred, m_states->NonPremultiplied());

	for (BaseScreen* screen : m_activeScreens)
	{
		screen->DrawInGameObjects(m_spriteBatch);
	}

	m_spriteBatch->End();

	m_spriteBatch->Begin(SpriteSortMode_Deferred, m_states->NonPremultiplied());

	for (BaseScreen* screen : m_activeScreens)
	{
		screen->DrawScreenObjects(m_spriteBatch);
	}

	m_spriteBatch->End();
}


//-----------------------------------------------------------------------------------------------------------------------------------
void ScreenManager::HandleInput(DX::StepTimer const& timer)
{
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

	m_screensToAdd.push_back(screenToAdd);
}


//-----------------------------------------------------------------------------------------------------------------------------------
void ScreenManager::RemoveScreen(BaseScreen* screenToRemove)
{
	m_screensToRemove.push_back(screenToRemove);
}
