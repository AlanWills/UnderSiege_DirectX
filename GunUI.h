#pragma once

#include "Menu.h"
#include "GunData.h"

class GunUI : public Menu
{
public:
	GunUI(Microsoft::WRL::ComPtr<ID3D11Device> device, const char* gunDataAsset, const Vector2& localPosition);
	~GunUI();

	void LoadContent(ID3D11Device* device) override;

protected:
	void AddInitialUI() override;

private:
	/// \brief The gun data for the loadout we selected - we will use this to build information UI
	std::unique_ptr<GunData> m_gunData;
};

