#include "pch.h"
#include "BaseScreenData.h"


//-----------------------------------------------------------------------------------------------------------------------------------
BaseScreenData::BaseScreenData(const char* dataAsset) :
	BaseData(dataAsset)
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
BaseScreenData::~BaseScreenData()
{
	
}


//-----------------------------------------------------------------------------------------------------------------------------------
const std::wstring BaseScreenData::GetDisplayName() const
{
	return GenericUtils::CharToWChar(GetDocument()->RootElement()->FirstChildElement("DisplayName")->GetText());
}


//-----------------------------------------------------------------------------------------------------------------------------------
const char* BaseScreenData::GetBackgroundAsset() const
{
	return GetDocument()->RootElement()->FirstChildElement("BackgroundTextureAsset")->GetText();
}