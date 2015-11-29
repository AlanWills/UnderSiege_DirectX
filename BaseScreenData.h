#pragma once

#include "tinyxml2.h"

using namespace tinyxml2;

class BaseScreenData
{
public:
	BaseScreenData();
	~BaseScreenData();

	void LoadData(const char* filename);
	const char* GetBackgroundAsset() const;

private:
	tinyxml2::XMLDocument* m_document;
};
