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
const char* LoadoutData::GetCharacterTextureAsset() const
{
	return m_document->RootElement()->FirstChildElement("CharacterTextureAsset")->GetText();
}


//-----------------------------------------------------------------------------------------------------------------------------------
const float LoadoutData::GetSpeed() const
{
	float speed = 0;
	m_document->RootElement()->FirstChildElement("Speed")->QueryFloatText(&speed);
	return speed;
}


//-----------------------------------------------------------------------------------------------------------------------------------
const float LoadoutData::GetArmour() const
{
	float armour = 0;
	m_document->RootElement()->FirstChildElement("Armour")->QueryFloatText(&armour);
	return armour;
}


//-----------------------------------------------------------------------------------------------------------------------------------
const char* LoadoutData::GetGunDataAsset() const
{
	return m_document->RootElement()->FirstChildElement("GunDataAsset")->GetText();
}