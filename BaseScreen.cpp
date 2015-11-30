#include "pch.h"
#include "BaseScreen.h"
#include "ScreenManager.h"


//-----------------------------------------------------------------------------------------------------------------------------------
BaseScreen::BaseScreen(ScreenManager* screenManager, const char* dataAsset, Microsoft::WRL::ComPtr<ID3D11Device> device) :
m_screenManager(screenManager),
m_device(device),
m_dataAsset(dataAsset),
m_baseScreenData(nullptr),
m_begun(false),
m_active(false),
m_visible(false),
m_acceptsInput(false),
m_alive(false),
m_background(nullptr)
{
	m_gameObjects.reset(new GameObjects(device));
	m_inGameUIObjects.reset(new InGameUIObjects(device));
	m_screenUIObjects.reset(new ScreenUIObjects(device));

}


//-----------------------------------------------------------------------------------------------------------------------------------
BaseScreen::~BaseScreen()
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
void BaseScreen::LoadContent()
{
	m_baseScreenData.reset(new BaseScreenData());
	m_baseScreenData->LoadData(m_dataAsset);

	m_gameObjects->LoadContent();
	m_inGameUIObjects->LoadContent();
	m_screenUIObjects->LoadContent();

	m_background.reset(new ScreenUIObject(Vector2(m_screenManager->GetScreenCentre() * 2), m_screenManager->GetScreenCentre(), m_baseScreenData->GetBackgroundAsset(), BaseObject::LoadType::kTexture));
	m_background->LoadContent(m_device.Get());
}


//-----------------------------------------------------------------------------------------------------------------------------------
void BaseScreen::Initialize()
{
	m_gameObjects->Initialize();
	m_inGameUIObjects->Initialize();
	m_screenUIObjects->Initialize();

	m_background->Initialize();

	m_alive = true;
	Show();
}


//-----------------------------------------------------------------------------------------------------------------------------------
void BaseScreen::Begin()
{
	m_begun = true;
}


//-----------------------------------------------------------------------------------------------------------------------------------
void BaseScreen::Update(DX::StepTimer const& timer)
{
	if (m_active)
	{
		if (!m_begun)
		{
			Begin();
		}

		m_gameObjects->Update(timer);
		m_inGameUIObjects->Update(timer);
		m_screenUIObjects->Update(timer);
	}
}


//-----------------------------------------------------------------------------------------------------------------------------------
void BaseScreen::DrawInGameObjects(SpriteBatch* spriteBatch)
{
	if (m_visible)
	{
		m_gameObjects->Draw(spriteBatch);
		m_inGameUIObjects->Draw(spriteBatch);
	}
}


//-----------------------------------------------------------------------------------------------------------------------------------
void BaseScreen::DrawScreenObjects(SpriteBatch* spriteBatch)
{
	if (m_visible)
	{
		m_screenUIObjects->Draw(spriteBatch);
	}
}


//-----------------------------------------------------------------------------------------------------------------------------------
void BaseScreen::DrawBackground(SpriteBatch* spriteBatch)
{
	if (m_visible)
	{
		m_background->Draw(spriteBatch);
	}
}


//-----------------------------------------------------------------------------------------------------------------------------------
void BaseScreen::HandleInput(DX::StepTimer const& timer)
{
	if (m_acceptsInput)
	{
		m_gameObjects->HandleInput(timer);
		m_inGameUIObjects->HandleInput(timer);
		m_screenUIObjects->HandleInput(timer);
	}
}


//-----------------------------------------------------------------------------------------------------------------------------------
void BaseScreen::Transition(BaseScreen* transitionTo)
{
	m_screenManager->AddScreen(transitionTo);
	m_screenManager->RemoveScreen(this);
}


//-----------------------------------------------------------------------------------------------------------------------------------
void BaseScreen::Show()
{
	m_active = true;
	m_visible = true;
	m_acceptsInput = true;
}


//-----------------------------------------------------------------------------------------------------------------------------------
void BaseScreen::Hide()
{
	m_active = false;
	m_visible = false;
	m_acceptsInput = false;
}

/////////////// Utility function wrappers for the object managers

//-----------------------------------------------------------------------------------------------------------------------------------
void BaseScreen::AddGameObject(GameObject* gameObject, bool load, bool initialize)
{
	m_gameObjects->AddObject(gameObject, load, initialize);
}


//-----------------------------------------------------------------------------------------------------------------------------------
void BaseScreen::RemoveGameObject(GameObject* gameObject)
{
	m_gameObjects->RemoveObject(gameObject);
}


//-----------------------------------------------------------------------------------------------------------------------------------
void BaseScreen::AddInGameUIObject(InGameUIObject* inGameUIObject, bool load, bool initialize)
{
	m_inGameUIObjects->AddObject(inGameUIObject, load, initialize);
}


//-----------------------------------------------------------------------------------------------------------------------------------
void BaseScreen::RemoveInGameUIObject(InGameUIObject* inGameUIObject)
{
	m_inGameUIObjects->RemoveObject(inGameUIObject);
}


//-----------------------------------------------------------------------------------------------------------------------------------
void BaseScreen::AddScreenUIObject(ScreenUIObject* screenUIObject, bool load, bool initialize)
{
	m_screenUIObjects->AddObject(screenUIObject, load, initialize);
}


//-----------------------------------------------------------------------------------------------------------------------------------
void BaseScreen::RemoveScreenUIObject(ScreenUIObject* screenUIObject)
{
	m_screenUIObjects->RemoveObject(screenUIObject);
}

/////////////// end
