#pragma once

#include "GunData.h"
#include "UIObject.h"

class Gun
{
public:
	Gun(const char* dataAsset);
	~Gun();

	void LoadData();

private:
	std::unique_ptr<GunData> m_gunData;

	/// \brief A UI object representing the muzzle flash of the gun.  When we fire we will set it's opacity to 1 and it will slowly decay
	std::unique_ptr<UIObject> m_muzzleFlash;
};

