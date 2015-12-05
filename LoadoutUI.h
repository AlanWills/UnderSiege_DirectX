#pragma once

#include "Menu.h"
#include "LoadoutData.h"

class LoadoutUI : public Menu
{
public:
	LoadoutUI(Microsoft::WRL::ComPtr<ID3D11Device> device, const char* loadoutDataAsset, const Vector2& localPosition);
	~LoadoutUI();

	/// \brief Loads the loadout data for this menu and all uiobjects we have added
	void LoadContent(ID3D11Device* device) override;

protected:
	/// \brief Adds the loadout data UI
	void AddInitialUI() override;

private:
	/// \brief The data for this loadout - we will use this to build information UI
	std::unique_ptr<LoadoutData> m_loadoutData;
	const char* m_loadoutDataAsset;
};