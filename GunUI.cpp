#include "pch.h"

#include "ScreenManager.h"

#include "GunUI.h"
#include "Label.h"


//-----------------------------------------------------------------------------------------------------------------------------------
GunUI::GunUI(Microsoft::WRL::ComPtr<ID3D11Device> device, const char* gunDataAsset, const Vector2& localPosition)
	: Menu(device, localPosition, "", BaseObject::kNoLoad, nullptr, FLT_MAX),
	m_gunData(new GunData(gunDataAsset))
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
GunUI::~GunUI()
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
void GunUI::AddInitialUI()
{
	assert(m_gunData.get());

	// Add all the UI for the gun here

	// Gun image
	UIObject* gunImage = new UIObject(Vector2(0, -ScreenManager::GetScreenCentre().y * 0.25f), m_gunData->GetGunTextureAsset(), LoadType::kTexture, this);
	// For some reason I have to do this to make it appear less black
	gunImage->SetColour(Color(5, 5, 5, 1));
	AddUIObject(gunImage);

	// Gun name
	Label* displayName = new Label(Vector2(0, ScreenManager::GetScreenCentre().y * 0.25f), m_gunData->GetDisplayName(), this);
	AddUIObject(displayName);

	// Gun damage
	Label* gunDamage = new Label(Vector2(0, 40), L"Damage: " + to_wstring(m_gunData->GetDamage()), displayName);
	AddUIObject(gunDamage);

	// Gun fire rate
	Label* gunFireRate = new Label(Vector2(0, 40), L"Fire Rate: " + to_wstring(m_gunData->GetFireRate()), gunDamage);
	AddUIObject(gunFireRate);

	// Magazine size
	Label* magazineSize = new Label(Vector2(0, 40), L"Magazine Size: " + to_wstring(m_gunData->GetMagazineSize()), gunFireRate);
	AddUIObject(magazineSize);
}


//-----------------------------------------------------------------------------------------------------------------------------------
void GunUI::LoadContent(ID3D11Device* device)
{
	m_gunData->LoadData();

	Menu::LoadContent(device);
}