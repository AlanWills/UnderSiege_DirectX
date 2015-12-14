#include "pch.h"

#include "ScreenManager.h"
#include "SelectLoadoutScreen.h"
#include "SelectWeaponScreen.h"

#include "Button.h"


//-----------------------------------------------------------------------------------------------------------------------------------
SelectLoadoutScreen::SelectLoadoutScreen(ScreenManager* screenManager, const char* dataAsset) :
	BaseScreen(screenManager, dataAsset),
	m_currentLoadout(0),
	m_numLoadouts(0)
{
	m_numLoadouts = (int)GetLoadoutAssets().size();
	assert(m_numLoadouts > 0);
}


//-----------------------------------------------------------------------------------------------------------------------------------
SelectLoadoutScreen::~SelectLoadoutScreen()
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
void SelectLoadoutScreen::LoadContent()
{
	BaseScreen::LoadContent();

	for (int i = 0; i < m_numLoadouts; i++)
	{
		m_loadoutUI.push_back(std::unique_ptr<LoadoutUI>(new LoadoutUI(GetDevice(), GetLoadoutAssets()[i], GetScreenCentre())));
		m_loadoutUI[i]->LoadContent(GetDevice().Get());
	}

	assert(m_numLoadouts == m_loadoutUI.size());
}


//-----------------------------------------------------------------------------------------------------------------------------------
void SelectLoadoutScreen::AddInitialUI()
{
	BaseScreen::AddInitialUI();

	// Add the select loadout button
	Button* selectLoadout = new Button(Vector2(GetScreenCentre().x * 1.25f, GetScreenCentre().y * 1.5f), L"Select Loadout");
	selectLoadout->SetClickFunction([this]()
	{
		Transition(new SelectWeaponScreen(GetLoadoutAssets()[m_currentLoadout], GetScreenManager()));
	});

	AddScreenUIObject(selectLoadout);
}


//-----------------------------------------------------------------------------------------------------------------------------------
void SelectLoadoutScreen::Initialize()
{
	BaseScreen::Initialize();

	for (auto& loadoutUI : m_loadoutUI)
	{
		loadoutUI->Initialize();
	}
}


//-----------------------------------------------------------------------------------------------------------------------------------
void SelectLoadoutScreen::DrawScreenObjects(SpriteBatch* spriteBatch, SpriteFont* spriteFont)
{
	BaseScreen::DrawScreenObjects(spriteBatch, spriteFont);

	assert(m_currentLoadout >= 0 && m_currentLoadout < m_numLoadouts);
	m_loadoutUI[m_currentLoadout]->Draw(spriteBatch, spriteFont);
}


//-----------------------------------------------------------------------------------------------------------------------------------
void SelectLoadoutScreen::HandleInput(DX::StepTimer const& timer)
{
	BaseScreen::HandleInput(timer);

	if (GetScreenManager()->GetKeyboardInput().IsKeyPressed(Keyboard::Keys::Down))
	{
		m_currentLoadout--;
		m_currentLoadout = MathUtils::Clamp<int>(m_currentLoadout, 0, m_numLoadouts - 1);

		OnCurrentLoadoutChanged();
	}
	else if (GetScreenManager()->GetKeyboardInput().IsKeyPressed(Keyboard::Keys::Up))
	{
		m_currentLoadout++;
		m_currentLoadout = MathUtils::Clamp<int>(m_currentLoadout, 0, m_numLoadouts - 1);

		OnCurrentLoadoutChanged();
	}
}


//-----------------------------------------------------------------------------------------------------------------------------------
void SelectLoadoutScreen::OnCurrentLoadoutChanged()
{
	for (auto& loadoutUI : m_loadoutUI)
	{
		loadoutUI->Hide();
	}

	m_loadoutUI[m_currentLoadout]->Show();
}