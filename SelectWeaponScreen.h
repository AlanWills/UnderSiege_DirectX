#pragma once

#include "BaseScreen.h"
#include "GunData.h"

class LoadoutData;

class SelectWeaponScreen : public BaseScreen
{
public:
	SelectWeaponScreen(const char* loadoutAsset, ScreenManager* screenManager, const char* dataAsset = "SelectWeaponScreen.xml");
	~SelectWeaponScreen();

	void AddInitialUI() override;

private:
	std::unique_ptr<LoadoutData> m_loadoutData;
};

