#include "pch.h"
#include "SelectWeaponScreen.h"


//-----------------------------------------------------------------------------------------------------------------------------------
SelectWeaponScreen::SelectWeaponScreen(const char* loadoutGunAsset, ScreenManager* screenManager, const char* dataAsset) :
	BaseScreen(screenManager, dataAsset),
	m_gunData(new GunData(loadoutGunAsset))
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
SelectWeaponScreen::~SelectWeaponScreen()
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
void SelectWeaponScreen::AddInitialUI()
{
	BaseScreen::AddInitialUI();


}


//-----------------------------------------------------------------------------------------------------------------------------------
void SelectWeaponScreen::LoadContent()
{
	BaseScreen::LoadContent();
}