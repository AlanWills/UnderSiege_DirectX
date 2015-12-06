#include "pch.h"

#include "GameplayScreenData.h"


//-----------------------------------------------------------------------------------------------------------------------------------
GameplayScreenData::GameplayScreenData(const char* dataAsset) :
	BaseScreenData(dataAsset)
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
GameplayScreenData::~GameplayScreenData()
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
const char* GameplayScreenData::GetTilemapDataAsset() const
{
	return GetDocument()->RootElement()->FirstChildElement("TilemapDataAsset")->GetText();
}