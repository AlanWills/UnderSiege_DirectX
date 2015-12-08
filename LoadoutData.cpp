#include "pch.h"
#include "LoadoutData.h"


//-----------------------------------------------------------------------------------------------------------------------------------
LoadoutData::LoadoutData(const char* dataAsset) :
	BaseData(dataAsset)
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


//-----------------------------------------------------------------------------------------------------------------------------------
const Vector2 LoadoutData::GetBarrelOffset() const
{
	Vector2 barrelOffset(Vector2::Zero);
	GetDocument()->RootElement()->FirstChildElement("BarrelOffsetX")->QueryFloatText(&barrelOffset.x);
	GetDocument()->RootElement()->FirstChildElement("BarrelOffsetY")->QueryFloatText(&barrelOffset.y);

	return barrelOffset;
}