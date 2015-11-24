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
ScreenManager::ScreenManager(ID3D11Device* device, ID3D11DeviceContext* deviceContext) :
m_device(device),
m_deviceContext(deviceContext),
m_spriteBatch(nullptr),
m_states(nullptr)
{
	UINT numViewports;
	m_deviceContext->RSGetViewports(&numViewports, &m_viewport);

	m_screenCentre = Vector2(m_viewport.Width, m_viewport.Height) * 0.5f;
}


//-----------------------------------------------------------------------------------------------------------------------------------
ScreenManager::~ScreenManager()
{
	delete m_spriteBatch;
	delete m_states;
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

}


//-----------------------------------------------------------------------------------------------------------------------------------
void ScreenManager::Update(DX::StepTimer const& timer)
{

}


//-----------------------------------------------------------------------------------------------------------------------------------
void ScreenManager::Render()
{
	m_spriteBatch->Begin(SpriteSortMode_Deferred, m_states->NonPremultiplied());

	m_spriteBatch->End();
}


//-----------------------------------------------------------------------------------------------------------------------------------
void ScreenManager::HandleInput(DX::StepTimer const& timer)
{

}
