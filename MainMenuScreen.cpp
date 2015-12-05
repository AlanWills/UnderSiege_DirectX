#include "pch.h"

#include "MainMenuScreen.h"
#include "SelectLoadoutScreen.h"

#include "ScreenManager.h"
#include "Button.h"
#include "Player.h"


//-----------------------------------------------------------------------------------------------------------------------------------
MainMenuScreen::MainMenuScreen(ScreenManager* screenManager, const char* dataAsset) :
	BaseScreen(screenManager, dataAsset)
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
MainMenuScreen::~MainMenuScreen()
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
void MainMenuScreen::AddInitialUI()
{
	BaseScreen::AddInitialUI();

	Button* beginButton = new Button(GetScreenCentre(), L"Begin", "Button.png");
	beginButton->SetClickFunction([this]()
	{
		Transition(new SelectLoadoutScreen(GetScreenManager(), "SelectLoadoutScreen.xml"));
	});

	AddScreenUIObject(beginButton);
}


//-----------------------------------------------------------------------------------------------------------------------------------
void MainMenuScreen::TransitionToSelectLoadoutScreen()
{
	
}