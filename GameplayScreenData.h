#pragma once

#include "BaseScreenData.h"

class GameplayScreenData : public BaseScreenData
{
public:
	GameplayScreenData(const char* dataAsset);
	~GameplayScreenData();

	const char* GetTilemapDataAsset() const;
};

