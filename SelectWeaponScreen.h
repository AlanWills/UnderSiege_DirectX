#pragma once

#include "BaseScreen.h"
#include "GunData.h"

class SelectWeaponScreen : public BaseScreen
{
public:
	SelectWeaponScreen(const char* loadoutGunDataAsset, ScreenManager* screenManager, const char* dataAsset = "SelectWeaponScreen.xml");
	~SelectWeaponScreen();

	void AddInitialUI() override;

private:
	const char* m_loadoutGunDataAsset;
};

