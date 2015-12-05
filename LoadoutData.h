#pragma once

#include "BaseData.h"

class LoadoutData : public BaseData
{
public:
	LoadoutData();
	~LoadoutData();

	const char* GetDisplayName() const;
	const char* GetCharacterTextureAsset() const;
	const float GetSpeed() const;
	const float GetArmour() const;
	const char* GetGunDataAsset() const;
};