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
	const tinyxml2::XMLDocument* GetDocument() const { return m_document.get(); }

private:
	std::unique_ptr<tinyxml2::XMLDocument> m_document;
};

