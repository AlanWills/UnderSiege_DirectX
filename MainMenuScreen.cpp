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
	AddScreenUIObject(new Label(Vector2(300, 50), Vector2(m_screenManager->GetScreenCentre().x, m_screenManager->GetScreenCentre().y * 0.25f), L"SHRAPNEL"));

	Button* beginButton = new Button(m_screenManager->GetScreenCentre(), L"Begin", "Button.png");
	AddScreenUIObject(beginButton);
}