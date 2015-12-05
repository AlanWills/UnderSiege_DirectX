#pragma once

#include "BaseData.h"

class BaseScreenData : public BaseData
{
public:
	BaseScreenData();
	~BaseScreenData();

	const char* GetDisplayName() const;
	const char* GetBackgroundAsset() const;
};

