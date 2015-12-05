#include "pch.h"
#include "LoadoutData.h"


//-----------------------------------------------------------------------------------------------------------------------------------
LoadoutData::LoadoutData()
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
LoadoutData::~LoadoutData()
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
const std::wstring LoadoutData::GetDisplayName() const
{
	return GenericUtils::CharToWChar(GetDocument()->RootElement()->FirstChildElement("DisplayName")->GetText());
}


//-----------------------------------------------------------------------------------------------------------------------------------
const char* LoadoutData::GetUITextureAsset() const
{
	return GetDocument()->RootElement()->FirstChildElement("UITextureAsset")->GetText();
}


//-----------------------------------------------------------------------------------------------------------------------------------
const char* LoadoutData::GetGameTextureAsset() const
{
	return GetDocument()->RootElement()->FirstChildElement("GameTextureAsset")->GetText();
}


//-----------------------------------------------------------------------------------------------------------------------------------
const int LoadoutData::GetSpeed() const
{
	int speed = 0;
	GetDocument()->RootElement()->FirstChildElement("Speed")->QueryIntText(&speed);
	return speed;
}


//-----------------------------------------------------------------------------------------------------------------------------------
const int LoadoutData::GetArmour() const
{
	int armour = 0;
	GetDocument()->RootElement()->FirstChildElement("Armour")->QueryIntText(&armour);
	return armour;
}


//-----------------------------------------------------------------------------------------------------------------------------------
const char* LoadoutData::GetGunDataAsset() const
{
	return GetDocument()->RootElement()->FirstChildElement("GunDataAsset")->GetText();
}