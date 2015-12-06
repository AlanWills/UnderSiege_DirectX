#pragma once

#include "BaseScreen.h"
#include "GunData.h"

class SelectWeaponScreen : public BaseScreen
{
public:
	SelectWeaponScreen(const char* loadoutGunAsset, ScreenManager* screenManager, const char* dataAsset = "SelectWeaponScreen.xml");
	~SelectWeaponScreen();

	void LoadContent() override;

	void AddInitialUI() override;

private:
	/// \brief Gun Data that we will be showing
	std::unique_ptr<GunData> m_gunData;
};

