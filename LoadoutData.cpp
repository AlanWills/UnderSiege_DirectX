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
const char* LoadoutData::GetDisplayName() const
{
	return GetDocument()->RootElement()->FirstChildElement("DisplayName")->GetText();
}


//-----------------------------------------------------------------------------------------------------------------------------------
const char* LoadoutData::GetCharacterTextureAsset() const
{
	return GetDocument()->RootElement()->FirstChildElement("CharacterTextureAsset")->GetText();
}


//-----------------------------------------------------------------------------------------------------------------------------------
const float LoadoutData::GetSpeed() const
{
	float speed = 0;
	GetDocument()->RootElement()->FirstChildElement("Speed")->QueryFloatText(&speed);
	return speed;
}


//-----------------------------------------------------------------------------------------------------------------------------------
const float LoadoutData::GetArmour() const
{
	float armour = 0;
	GetDocument()->RootElement()->FirstChildElement("Armour")->QueryFloatText(&armour);
	return armour;
}


//-----------------------------------------------------------------------------------------------------------------------------------
const char* LoadoutData::GetGunDataAsset() const
{
	return GetDocument()->RootElement()->FirstChildElement("GunDataAsset")->GetText();
}