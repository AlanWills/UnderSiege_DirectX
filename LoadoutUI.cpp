#include "pch.h"

#include "LoadoutUI.h"
#include "ScreenManager.h"

#include "Label.h"


//-----------------------------------------------------------------------------------------------------------------------------------
LoadoutUI::LoadoutUI(Microsoft::WRL::ComPtr<ID3D11Device> device, const char* loadoutDataAsset, const Vector2& localPosition) :
	Menu(device, localPosition, "", BaseObject::kNoLoad, nullptr, FLT_MAX),
	m_loadoutData(new LoadoutData()),
	m_loadoutDataAsset(loadoutDataAsset)
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
LoadoutUI::~LoadoutUI()
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
void LoadoutUI::LoadContent(ID3D11Device* device)
{
	m_loadoutData->LoadData(m_loadoutDataAsset);
	assert(m_loadoutData.get());

	Menu::LoadContent(device);
}


//-----------------------------------------------------------------------------------------------------------------------------------
void LoadoutUI::AddInitialUI()
{
	// Check that we have loaded the data before calling this function
	assert(m_loadoutData.get());

	// Add all the ui for the loadout here

	// Add the image that the player will have if they pick this loadout
	UIObject* m_playerImage = new UIObject(Vector2(-ScreenManager::GetScreenCentre().x * 0.25f, 0), m_loadoutData->GetUITextureAsset(), LoadType::kTexture, this);
	AddUIObject(m_playerImage, true);

	// Add the loadout display name
	Label* displayName = new Label(Vector2(ScreenManager::GetScreenCentre().x * 0.25f, -ScreenManager::GetScreenCentre().y * 0.25f), m_loadoutData->GetDisplayName(), this);
	AddUIObject(displayName);

	// Add the loadout armour text
	Label* armour = new Label(Vector2(0, 40), L"Armour: " + to_wstring(m_loadoutData->GetArmour()), displayName);
	AddUIObject(armour);

	// Add the loadout speed text
	Label* speed = new Label(Vector2(0, 40), L"Speed: " + to_wstring(m_loadoutData->GetSpeed()), armour);
	AddUIObject(speed);
}