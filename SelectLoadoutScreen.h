#pragma once

#include "BaseScreen.h"

class SelectLoadoutScreen : public BaseScreen
{
public:
	SelectLoadoutScreen(ScreenManager* screenManager, const char* dataAsset, Microsoft::WRL::ComPtr<ID3D11Device> device);
	~SelectLoadoutScreen();
};