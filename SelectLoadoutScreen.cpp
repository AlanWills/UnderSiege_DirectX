#include "pch.h"

#include "SelectLoadoutScreen.h"
#include "ScreenManager.h"


//-----------------------------------------------------------------------------------------------------------------------------------
SelectLoadoutScreen::SelectLoadoutScreen(ScreenManager* screenManager, const char* dataAsset) :
	BaseScreen(screenManager, dataAsset),
	m_currentLoadout(0),
	m_numLoadouts(0)
{
	m_loadoutDataAssets.push_back("HeavyGunner.xml");

	m_numLoadouts = m_loadoutDataAssets.size();
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

	for (size_t i = 0; i < m_numLoadouts; i++)
	{
		m_loadoutUI.push_back(std::unique_ptr<LoadoutUI>(new LoadoutUI(GetDevice(), m_loadoutDataAssets[i], GetScreenManager()->GetScreenCentre())));
		m_loadoutUI[i]->LoadContent(GetDevice().Get());
	}

	assert(m_numLoadouts == m_loadoutUI.size());
}


//-----------------------------------------------------------------------------------------------------------------------------------
void SelectLoadoutScreen::Initialize()
{
	BaseScreen::Initialize();

	for (size_t i = 0; i < m_numLoadouts; ++i)
	{
		m_loadoutUI[i]->Initialize();
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
		m_currentLoadout = MathUtils::Clamp<size_t>(m_currentLoadout, 0, m_numLoadouts - 1);

		OnCurrentLoadoutChanged();
	}
	else if (GetScreenManager()->GetKeyboardInput().IsKeyPressed(Keyboard::Keys::Up))
	{
		m_currentLoadout++;
		m_currentLoadout = MathUtils::Clamp<size_t>(m_currentLoadout, 0, m_numLoadouts - 1);

		OnCurrentLoadoutChanged();
	}
}


//-----------------------------------------------------------------------------------------------------------------------------------
void SelectLoadoutScreen::OnCurrentLoadoutChanged()
{
	for (size_t i = 0; i < m_numLoadouts; ++i)
	{
		m_loadoutUI[i]->Hide();
	}

	m_loadoutUI[m_currentLoadout]->Show();
}