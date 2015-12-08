#pragma once

#include "BaseData.h"

class GunData : public BaseData
{
public:
	GunData(const char* dataAsset);
	~GunData();

	const std::wstring GetDisplayName() const;
	const char* GetGunTextureAsset() const;
	const char* GetMuzzleFlashTextureAsset() const;
	const char* GetBulletTexureAsset() const;
	const int GetDamage() const;
	const float GetFireRate() const;
	const int GetMagazineSize() const;
	const float GetBulletSpread() const;
};