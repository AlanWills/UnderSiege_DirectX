#include "pch.h"
#include "BaseScreen.h"
#include "ScreenManager.h"


//-----------------------------------------------------------------------------------------------------------------------------------
BaseScreen::BaseScreen(ScreenManager* screenManager, std::wstring& dataAsset) :
m_screenManager(screenManager),
m_dataAsset(dataAsset),
m_begun(false),
m_active(false),
m_visible(false),
m_acceptsInput(false),
m_alive(false)
{
	
}


//-----------------------------------------------------------------------------------------------------------------------------------
BaseScreen::~BaseScreen()
{
	
}


//-----------------------------------------------------------------------------------------------------------------------------------
void BaseScreen::Begin()
{
	m_begun = true;
}
