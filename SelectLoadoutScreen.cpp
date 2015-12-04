#include "pch.h"
#include "SelectLoadoutScreen.h"


//-----------------------------------------------------------------------------------------------------------------------------------
SelectLoadoutScreen::SelectLoadoutScreen(ScreenManager* screenManager, const char* dataAsset, Microsoft::WRL::ComPtr<ID3D11Device> device) :
	BaseScreen(screenManager, dataAsset, device)
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
SelectLoadoutScreen::~SelectLoadoutScreen()
{
}
