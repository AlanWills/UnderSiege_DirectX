#include "pch.h"
#include "BaseScreenData.h"


//-----------------------------------------------------------------------------------------------------------------------------------
BaseScreenData::BaseScreenData() :
	BaseData()
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
BaseScreenData::~BaseScreenData()
{
	
}


//-----------------------------------------------------------------------------------------------------------------------------------
const char* BaseScreenData::GetDisplayName() const
{
	return GetDocument()->RootElement()->FirstChildElement("DisplayName")->GetText();
}


//-----------------------------------------------------------------------------------------------------------------------------------
const char* BaseScreenData::GetBackgroundAsset() const
{
	return GetDocument()->RootElement()->FirstChildElement("BackgroundTextureAsset")->GetText();
}