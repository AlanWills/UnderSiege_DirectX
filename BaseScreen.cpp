#include "pch.h"
#include "BaseScreen.h"
#include "ScreenManager.h"

#include "Label.h"


//-----------------------------------------------------------------------------------------------------------------------------------
BaseScreen::BaseScreen(ScreenManager* screenManager, const char* dataAsset) :
m_screenManager(screenManager),
m_dataAsset(dataAsset),
m_baseScreenData(nullptr),
m_begun(false),
m_active(false),
m_visible(false),
m_acceptsInput(false),
m_alive(false),
m_background(nullptr)
{
	m_gameObjects.reset(new GameObjects(m_screenManager->GetDevice()));
	m_inGameUIObjects.reset(new UIObjects(m_screenManager->GetDevice()));
	m_screenUIObjects.reset(new UIObjects(m_screenManager->GetDevice()));
}


//-----------------------------------------------------------------------------------------------------------------------------------
BaseScreen::~BaseScreen()
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
void BaseScreen::LoadContent(ID3D11Device* device)
{
	m_baseScreenData.reset(new BaseScreenData());
	m_baseScreenData->LoadData(m_dataAsset);

	AddInitialUI();

	m_gameObjects->LoadContent(device);
	m_inGameUIObjects->LoadContent(device);
	m_screenUIObjects->LoadContent(device);
}

//-----------------------------------------------------------------------------------------------------------------------------------
void BaseScreen::AddInitialUI()
{
	// This has to be separate so we can draw it behind all the other objects
	m_background.reset(new UIObject(Vector2(m_screenManager->GetScreenCentre() * 2), m_screenManager->GetScreenCentre(), m_baseScreenData->GetBackgroundAsset(), BaseObject::LoadType::kTexture));
	m_background->LoadContent(m_screenManager->GetDevice().Get());

	AddScreenUIObject(new Label(Vector2(300, 50), Vector2(GetScreenManager()->GetScreenCentre().x, GetScreenManager()->GetScreenCentre().y * 0.25f), GenericUtils::CharToWChar(m_baseScreenData->GetDisplayName())));
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
void BaseScreen::DrawInGameObjects(SpriteBatch* spriteBatch, SpriteFont* spriteFont)
{
	if (m_visible)
	{
		m_gameObjects->Draw(spriteBatch, spriteFont);
		m_inGameUIObjects->Draw(spriteBatch, spriteFont);
	}
}


//-----------------------------------------------------------------------------------------------------------------------------------
void BaseScreen::DrawScreenObjects(SpriteBatch* spriteBatch, SpriteFont* spriteFont)
{
	if (m_visible)
	{
		m_screenUIObjects->Draw(spriteBatch, spriteFont);
	}
}


//-----------------------------------------------------------------------------------------------------------------------------------
void BaseScreen::DrawBackground(SpriteBatch* spriteBatch, SpriteFont* spriteFont)
{
	if (m_visible)
	{
		m_background->Draw(spriteBatch, spriteFont);
	}
}


//-----------------------------------------------------------------------------------------------------------------------------------
void BaseScreen::HandleInput(DX::StepTimer const& timer)
{
	if (m_acceptsInput)
	{
		const Vector2 mouseScreenPosition = ScreenManager::GetGameMouse().GetWorldPosition();
		const Vector2 mouseInGamePosition = ScreenManager::GetGameMouse().GetInGamePosition();

		m_gameObjects->HandleInput(timer, mouseInGamePosition);
		m_inGameUIObjects->HandleInput(timer, mouseInGamePosition);
		m_screenUIObjects->HandleInput(timer, mouseScreenPosition);
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
void BaseScreen::AddInGameUIObject(UIObject* inGameUIObject, bool load, bool initialize)
{
	m_inGameUIObjects->AddObject(inGameUIObject, load, initialize);
}


//-----------------------------------------------------------------------------------------------------------------------------------
void BaseScreen::RemoveInGameUIObject(UIObject* inGameUIObject)
{
	m_inGameUIObjects->RemoveObject(inGameUIObject);
}


//-----------------------------------------------------------------------------------------------------------------------------------
void BaseScreen::AddScreenUIObject(UIObject* screenUIObject, bool load, bool initialize)
{
	m_screenUIObjects->AddObject(screenUIObject, load, initialize);
}


//-----------------------------------------------------------------------------------------------------------------------------------
void BaseScreen::RemoveScreenUIObject(UIObject* screenUIObject)
{
	m_screenUIObjects->RemoveObject(screenUIObject);
}

/////////////// end
