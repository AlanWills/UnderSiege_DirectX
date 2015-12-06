#include "pch.h"
#include "GunUI.h"


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

}


//-----------------------------------------------------------------------------------------------------------------------------------
void GunUI::LoadContent(ID3D11Device* device)
{
	m_gunData->LoadData();

	Menu::LoadContent(device);
}
