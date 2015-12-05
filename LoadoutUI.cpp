#include "pch.h"
#include "LoadoutUI.h"
#include "ScreenManager.h"


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
	UIObject* m_playerImage = new UIObject(Vector2(ScreenManager::GetScreenCentre()), m_loadoutData->GetCharacterTextureAsset(), LoadType::kTexture, this);
	AddUIObject(m_playerImage, true);
}