#pragma once

#include "BaseData.h"

class LoadoutData : public BaseData
{
public:
	LoadoutData();
	~LoadoutData();

	const std::wstring GetDisplayName() const;
	const char* GetUITextureAsset() const;
	const char* GetGameTextureAsset() const;
	const int GetSpeed() const;
	const int GetArmour() const;
	const char* GetGunDataAsset() const;
};