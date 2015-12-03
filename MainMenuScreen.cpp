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
	Player* player = new Player(Vector2(500, 500), "HeavySoldier.png", BaseObject::LoadType::kTexture);
	AddGameObject(player);
}