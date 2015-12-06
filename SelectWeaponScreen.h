#pragma once

#include "BaseScreen.h"

class SelectWeaponScreen : public BaseScreen
{
public:
	SelectWeaponScreen(ScreenManager* screenManager, const char* dataAsset);
	~SelectWeaponScreen();
};

