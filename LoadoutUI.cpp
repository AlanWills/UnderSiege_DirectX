#include "pch.h"

#include "LoadoutUI.h"
#include "ScreenManager.h"

#include "Label.h"
#include "Bar.h"


//-----------------------------------------------------------------------------------------------------------------------------------
LoadoutUI::LoadoutUI(Microsoft::WRL::ComPtr<ID3D11Device> device, const char* loadoutDataAsset, const Vector2& localPosition) :
	Menu(device, localPosition, "", BaseObject::kNoLoad, nullptr, FLT_MAX),
	m_loadoutData(new LoadoutData(loadoutDataAsset))
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
LoadoutUI::~LoadoutUI()
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
void LoadoutUI::LoadContent(ID3D11Device* device)
{
	m_loadoutData->LoadData();
	assert(m_loadoutData.get());

	Menu::LoadContent(device);
}


//-----------------------------------------------------------------------------------------------------------------------------------
void LoadoutUI::AddInitialUI()
{
	// Check that we have loaded the data before calling this function
	assert(m_loadoutData.get());

	// Add all the UI for the loadout here

	// Add the image that the player will have if they pick this loadout
	UIObject* playerImage = new UIObject(Vector2(-ScreenManager::GetScreenCentre().x * 0.25f, 0), m_loadoutData->GetUITextureAsset(), LoadType::kTexture, this);
	// For some reason I have to do this to make it appear less black
	playerImage->SetColour(Color(4, 4, 4, 1));
	AddUIObject(playerImage);

	// Add the loadout display name
	Label* displayName = new Label(Vector2(ScreenManager::GetScreenCentre().x * 0.25f, -ScreenManager::GetScreenCentre().y * 0.25f), m_loadoutData->GetDisplayName(), this);
	AddUIObject(displayName);

	// Add the loadout armour text
	Label* armour = new Label(Vector2(0, 40), L"Armour", displayName);
	AddUIObject(armour);

	const float armourSizeMultiplier = 2.5f;

	// Add the armour bar
	float armourValue = static_cast<float>(m_loadoutData->GetArmour());
	Bar* armourBar = new Bar(
		armourValue,
		Vector2(armourValue * armourSizeMultiplier, 20),
		Vector2(armourValue * armourSizeMultiplier * 0.5f + 60, 0),
		"ArmourBar.png", 
		LoadType::kTexture, 
		armour);
	AddUIObject(armourBar);

	// Add the loadout speed text
	Label* speed = new Label(Vector2(0, 40), L"Speed", armour);
	AddUIObject(speed);

	const float speedSizeMultiplier = 0.5f;

	// Add the speed bar
	float speedValue = static_cast<float>(m_loadoutData->GetSpeed());
	Bar* speedBar = new Bar(
		speedValue,
		Vector2(speedValue * speedSizeMultiplier, 20),
		Vector2(speedValue * speedSizeMultiplier * 0.5f + 60, 0),
		"SpeedBar.png",
		LoadType::kTexture,
		speed);
	AddUIObject(speedBar);
}