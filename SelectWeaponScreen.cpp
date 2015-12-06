#include "pch.h"

#include "ScreenManager.h"

#include "SelectWeaponScreen.h"
#include "SelectLoadoutScreen.h"
#include "GameplayScreen.h"

#include "GunUI.h"
#include "Button.h"

//-----------------------------------------------------------------------------------------------------------------------------------
SelectWeaponScreen::SelectWeaponScreen(const char* loadoutGunAsset, ScreenManager* screenManager, const char* dataAsset) :
	BaseScreen(screenManager, dataAsset),
	m_loadoutGunDataAsset(loadoutGunAsset)
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

	// Add the gunUI
	AddScreenUIObject(new GunUI(GetDevice(), m_loadoutGunDataAsset, GetScreenCentre()));

	// Button to transition back to the select loadout screen
	Button* backToLoadoutScreen = new Button(Vector2(200, ScreenManager::GetScreenDimensions().y - 100), L"Back");
	backToLoadoutScreen->SetClickFunction([this]()
	{
		Transition(new SelectLoadoutScreen(GetScreenManager()));
	});

	AddScreenUIObject(backToLoadoutScreen);

	// Button to start move to the next screen - level select or straight into game?
	Button* chooseWeapon = new Button(Vector2(ScreenManager::GetScreenDimensions().x - 200, ScreenManager::GetScreenDimensions().y - 100), L"Select Weapon");
	chooseWeapon->SetClickFunction([this]()
	{
		// Fill in the appropriate level
		Transition(new GameplayScreen(GetScreenManager(), ""));
	});

	AddScreenUIObject(chooseWeapon);
}