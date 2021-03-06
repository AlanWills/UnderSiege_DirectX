#pragma once

#include "LoadoutData.h"

class Loadout
{
public:
	Loadout(const char* dataAsset);
	~Loadout();

	void LoadData();
	const LoadoutData* GetData() const { return m_loadoutData.get(); }

private:
	// Unique pointer to loadout data
	std::unique_ptr<LoadoutData> m_loadoutData;
};

