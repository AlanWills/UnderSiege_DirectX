#include "pch.h"
#include "MainMenuScreen.h"

#include "Button.h"


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
	Button
}