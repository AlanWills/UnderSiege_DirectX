#include "pch.h"
#include "MainMenuScreen.h"

#include "ScreenManager.h"
#include "Button.h"
#include "Player.h"


//-----------------------------------------------------------------------------------------------------------------------------------
MainMenuScreen::MainMenuScreen(ScreenManager* screenManager, const char* dataAsset, Microsoft::WRL::ComPtr<ID3D11Device> device) :
	BaseScreen(screenManager, dataAsset, device)
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
MainMenuScreen::~MainMenuScreen()
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
void MainMenuScreen::AddInitialUI()
{
	AddScreenUIObject(new Label(Vector2(300, 50), Vector2(GetScreenManager()->GetScreenCentre().x, GetScreenManager()->GetScreenCentre().y * 0.25f), L"SHRAPNEL"));

	Button* beginButton = new Button(GetScreenManager()->GetScreenCentre(), L"Begin", "Button.png");
	AddScreenUIObject(beginButton);
}