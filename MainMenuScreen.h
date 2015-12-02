#pragma once

#include "BaseScreen.h"

class MainMenuScreen : public BaseScreen
{
public:
	MainMenuScreen(ScreenManager* screenManager, const char* dataAsset, Microsoft::WRL::ComPtr<ID3D11Device> device);
	~MainMenuScreen();

	void AddInitialUI() override;
};

