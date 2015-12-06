#pragma once

#include "BaseScreen.h"

class MainMenuScreen : public BaseScreen
{
public:
	MainMenuScreen(ScreenManager* screenManager, const char* dataAsset = "MainMenuScreen.xml");
	~MainMenuScreen();

	void AddInitialUI() override;
};

