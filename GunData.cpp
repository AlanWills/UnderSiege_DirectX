#include "pch.h"
#include "GunData.h"


//-----------------------------------------------------------------------------------------------------------------------------------
GunData::GunData(const char* dataAsset) :
	BaseData(dataAsset)
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
GunData::~GunData()
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
const std::wstring GunData::GetDisplayName() const
{
	return GenericUtils::CharToWChar(GetDocument()->RootElement()->FirstChildElement("DisplayName")->GetText());
}


//-----------------------------------------------------------------------------------------------------------------------------------
const char* GunData::GetGunTextureAsset() const
{
	return GetDocument()->RootElement()->FirstChildElement("GunTextureAsset")->GetText();
}


//-----------------------------------------------------------------------------------------------------------------------------------
const char* GunData::GetMuzzleFlashTextureAsset() const
{
	return GetDocument()->RootElement()->FirstChildElement("MuzzleFlashTextureAsset")->GetText();
}


//-----------------------------------------------------------------------------------------------------------------------------------
const char* GunData::GetBulletTexureAsset() const
{
	return GetDocument()->RootElement()->FirstChildElement("BulletTextureAsset")->GetText();
}


//-----------------------------------------------------------------------------------------------------------------------------------
const int GunData::GetDamage() const
{
	int damage = 0;
	GetDocument()->RootElement()->FirstChildElement("Damage")->QueryIntText(&damage);
	return damage;
}


//-----------------------------------------------------------------------------------------------------------------------------------
const float GunData::GetFireRate() const
{
	float fireRate = 0;
	GetDocument()->RootElement()->FirstChildElement("FireRate")->QueryFloatText(&fireRate);
	return fireRate;
}


//-----------------------------------------------------------------------------------------------------------------------------------
const int GunData::GetMagazineSize() const
{
	int magazineSize = 0;
	GetDocument()->RootElement()->FirstChildElement("MagazineSize")->QueryIntText(&magazineSize);
	return magazineSize;
}


//-----------------------------------------------------------------------------------------------------------------------------------
const float GunData::GetBulletSpread() const
{
	float bulletSpread = 0;
	GetDocument()->RootElement()->FirstChildElement("BulletSpread")->QueryFloatText(&bulletSpread);
	return bulletSpread;
}