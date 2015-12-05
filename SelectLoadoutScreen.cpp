#include "pch.h"

#include "SelectLoadoutScreen.h"
#include "ScreenManager.h"


//-----------------------------------------------------------------------------------------------------------------------------------
SelectLoadoutScreen::SelectLoadoutScreen(ScreenManager* screenManager, const char* dataAsset) :
	BaseScreen(screenManager, dataAsset)
{
	m_loadoutDataAssets.push_back("HeavyGunner.xml");

	m_loadoutUI.reserve(m_loadoutDataAssets.size());
}


//-----------------------------------------------------------------------------------------------------------------------------------
SelectLoadoutScreen::~SelectLoadoutScreen()
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
void SelectLoadoutScreen::LoadContent()
{
	BaseScreen::LoadContent();

	for (int i = 0; i < m_loadoutDataAssets.size(); i++)
	{
		m_loadoutUI[i].reset(new LoadoutUI(GetScreenManager()->GetDevice(), m_loadoutDataAssets[i], GetScreenManager()->GetScreenCentre()));
	}
}