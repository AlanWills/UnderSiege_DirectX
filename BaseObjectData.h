#pragma once

#include "tinyxml2.h"

using namespace tinyxml2;

class BaseObjectData
{
public:
	BaseObjectData();
	~BaseObjectData();

	void LoadData(const char* filename);
	const char* GetTextureAsset() const;

private:
	std::unique_ptr<tinyxml2::XMLDocument> m_document;
};

