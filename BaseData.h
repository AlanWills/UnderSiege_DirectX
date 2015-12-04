#pragma once

#include "tinyxml2.h"

using namespace tinyxml2;

class BaseData
{
public:
	BaseData();
	~BaseData();

	void LoadData(const char* filename);

protected:
	std::unique_ptr<tinyxml2::XMLDocument> m_document;
};

